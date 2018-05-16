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