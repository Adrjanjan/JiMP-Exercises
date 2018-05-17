//
// Created by adrja on 05/05/2018.
//

#include "MovieSubtitles.h"

void
moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                  std::ostream *out) {

    if (frame_per_second <= 0) throw SubtitlesException(0, "FPS is not positive: " + std::to_string(frame_per_second));

    int true_fps = offset_in_micro_seconds * frame_per_second / 1000;
    int line_count = 0;
    int prev_first = 0;
    std::pair<std::pair<int, int>, std::string> line;

    std::smatch capture_points;
    std::string subtitle_line, temp;

    while (in->good()) {
        std::getline(*in, subtitle_line);
        if (subtitle_line.empty())
            break;
        ++line_count;
        if (!std::regex_search(subtitle_line, capture_points, capture_point_pattern_)) {
            throw InvalidSubtitleLineFormat(line_count, subtitle_line);
        }

        line = std::make_pair(std::make_pair(std::stoi(capture_points[1].str()), std::stoi(capture_points[2].str())),
                              capture_points[3].str());

        if (line.first.first > line.first.second) {
            throw SubtitleEndBeforeStart(line_count, subtitle_line);
        }

        if (line.first.first + true_fps < 0) {
            throw NegativeFrameAfterShift(line_count, subtitle_line);
        }

        if (prev_first > line.first.first) {
            throw OutOfOrderFrames(line_count, subtitle_line);
        }

        prev_first = line.first.first;
        (*out) << "{" << line.first.first + true_fps << "}{" <<
               line.first.second + true_fps << "}" << line.second << std::endl;

    }
}

moviesubs::SubtitlesException::SubtitlesException(int line_number, const std::string &message)
        : std::invalid_argument("At line " + std::to_string(line_number) + ": " + message) {
    wrong_line_number_ = line_number;
}

int moviesubs::SubtitlesException::LineAt() const {
    return wrong_line_number_;
}

moviesubs::NegativeFrameAfterShift::NegativeFrameAfterShift(int line_number, const std::string &line)
        : SubtitlesException(line_number, line) {}

moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_number, const std::string &line)
        : SubtitlesException(line_number, line) {}

moviesubs::InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(int line_number, const std::string &line)
        : SubtitlesException(line_number, line) {}

moviesubs::MissingTimeSpecification::MissingTimeSpecification(int line_number, const std::string &line)
        : SubtitlesException(line_number, line) {}

moviesubs::OutOfOrderFrames::OutOfOrderFrames(int line_number, const std::string &line)
        : SubtitlesException(line_number, line) {}

void
moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                std::ostream *out) {

    if (frame_per_second <= 0) throw SubtitlesException(0, "FPS is not positive: " + std::to_string(frame_per_second));

    int line_count = 0, index, prev_index = 0;
    TimeHandler prev_first{0, 0, 0, 0};
    TimeHandler time_in{0, 0, 0, 0};
    TimeHandler time_out{0, 0, 0, 0};
    std::string text;

    std::smatch capture_points;
    std::string subtitle_line, temp;

    bool is_empty = false;

    while (in->good()) {
        while (!is_empty) {
            std::getline(*in, temp);
            if (temp == "\n") temp.erase();
            subtitle_line += temp + "\n";
            if (temp.empty()) {
                is_empty = true;
            }
        }

        if (subtitle_line.empty() || subtitle_line == "\n")
            break;
        ++line_count;

        if (!std::regex_search(subtitle_line, capture_points, capture_point_pattern_)) {
            throw InvalidSubtitleLineFormat(line_count, subtitle_line);
        }

        time_in = {std::stoi(capture_points[2].str()), std::stoi(capture_points[3].str()),
                   std::stoi(capture_points[4].str()), std::stoi(capture_points[5].str())};
        time_out = {std::stoi(capture_points[6].str()), std::stoi(capture_points[7].str()),
                    std::stoi(capture_points[8].str()), std::stoi(capture_points[9].str())};

        text = capture_points[10].str();
        index = std::stoi(capture_points[1].str());

        if (time_in.operator>(time_out)) {
            throw SubtitleEndBeforeStart(line_count, time_in.to_string() + " --> " + time_out.to_string());
        }
        time_out.AddMiliseconds(offset_in_micro_seconds);
        if (time_in.AddMiliseconds(offset_in_micro_seconds) < 0) {
            throw NegativeFrameAfterShift(line_count, subtitle_line);
        }

        if (prev_first > time_in || prev_index > index || prev_index + 1 != index) {
            throw OutOfOrderFrames(line_count, subtitle_line);
        }

        prev_first = time_in;
        prev_index = index;
        is_empty = false;
        subtitle_line.erase();
        (*out) << index << std::endl << time_in.to_string() << " --> " << time_out.to_string()
               << std::endl << text;
    }
}

moviesubs::SubRipSubtitles::TimeHandler::TimeHandler(int hours, int minutes, int seconds, int microseconds) {
    microseconds_ = ((hours * 60 + minutes) * 60 + seconds) * 1000 + microseconds;
}

std::string moviesubs::SubRipSubtitles::TimeHandler::to_string() const {
    int microseconds = microseconds_ % 1000;
    int seconds = ((microseconds_ - microseconds) / 1000) % 60;
    int minutes = ((microseconds_ - microseconds) / 1000 - seconds) / 60 % 60;
    int hours = (((microseconds_ - microseconds) / 1000 - seconds) / 60 - minutes) / 60;

    std::string mic = std::to_string(microseconds), sec = std::to_string(seconds), min = std::to_string(
            minutes), hou = std::to_string(hours);
    while (mic.size() < 3) mic = "0" + mic;
    if (seconds < 10) sec = "0" + sec;
    if (minutes < 10) min = "0" + min;
    if (hours < 10) hou = "0" + hou;

    return hou + ":" + min + ":" + sec + "," + mic;
}

moviesubs::SubRipSubtitles::TimeHandler &moviesubs::SubRipSubtitles::TimeHandler::AddMiliseconds(int other) {
    microseconds_ += other;
    return *this;
}

bool moviesubs::SubRipSubtitles::TimeHandler::operator>(const moviesubs::SubRipSubtitles::TimeHandler &other) const {
    return microseconds_ > other.microseconds_;
}

bool moviesubs::SubRipSubtitles::TimeHandler::operator<(int other) const {
    return microseconds_ < other;
}
