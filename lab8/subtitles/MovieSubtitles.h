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
        /* INDEX NEW_LINE
         * TIME_IN → TIME_OFF NEW_LINE
         * SUBTITLE1 NEW_LINE
         * SUBTITLE2 NEW_LINE NEW_LINE
         * gdzie INDEX - to numer klatki,
         * NEW_LINE to znak nowej linii,
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
