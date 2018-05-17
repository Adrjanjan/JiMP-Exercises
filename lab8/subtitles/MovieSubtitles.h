//
// Created by adrja on 05/05/2018.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
#include <stdexcept>
#include <regex>

namespace moviesubs {

    class MovieSubtitles {
    public:
        virtual void
        ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out) = 0;

        ~MovieSubtitles() = default;
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                 std::ostream *out) override;
        // {INT_ON}{INT_OFF}SUBTITLE
    private:
        std::regex capture_point_pattern_{R"(\n?\{([0-9]+)\}\{([0-9]+)\}((\{.+\})?.+))"};
    };

    class SubtitlesException : public std::invalid_argument {
    public:
        SubtitlesException(int line_number, const std::string &message);

        int LineAt() const;

    private:
        int wrong_line_number_;
    };

    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        NegativeFrameAfterShift(int line_number, const std::string &line);
    };

    class SubtitleEndBeforeStart : public SubtitlesException {
    public:
        SubtitleEndBeforeStart(int line_number, const std::string &line);

    };

    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
        InvalidSubtitleLineFormat(int line_number, const std::string &line);
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                 std::ostream *out) override;

    private:

        class TimeHandler {
        public:
            TimeHandler(int hours, int minutes, int seconds, int microseconds);

            std::string to_string() const;

            TimeHandler &AddMiliseconds(int other);

            bool operator>(const TimeHandler &other) const;

            bool operator<(int other) const;

        private:
            int microseconds_;
        };


        std::regex capture_point_pattern_{
                R"(([0-9]+)\n([0-9]+):([0-9]+):([0-9]+),([0-9]+) --> ([0-9]+):([0-9]+):([0-9]+),([0-9]+)\n((.*)\n(.*)?\n?\n))"};
        /* INDEX \n - 1
         * HH:MM:SS,mmm(TIME_IN)--> HH:MM:SS,mmm(TIME_OFF) \n - 2,3,4,5 --> 6,7,8,9
         * SUBTITLE1 \n - 11
         * SUBTITLE2 \n\n - 12
         *
         * gdzie INDEX - to numer klatki,
         * TIME_IN i TIME_OFF to moment pojawienia się i zniknięcia klatki
         * w formacie HH:MM:SS,mmm (godzina:minuta:sekundy,milisekundy).
         * Napisy mogą być wielolinijkowe, nowa klatka pojawia się po pustej linii.*/
    };

    class MissingTimeSpecification : public SubtitlesException {
    public:
        MissingTimeSpecification(int line_number, const std::string &line);
    };

    class OutOfOrderFrames : public SubtitlesException {
    public:
        OutOfOrderFrames(int line_number, const std::string &line);
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
