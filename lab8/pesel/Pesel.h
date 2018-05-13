//
// Created by adrja on 05/05/2018.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>

namespace academia {

    class Pesel {
    public:
        Pesel(std::string pesel);

        bool validatePESEL(const std::string pesel);

    private:
        std::string pesel_;
    };

    class AcademiaDataValidationError : public std::invalid_argument {
    public:
        AcademiaDataValidationError(const std::string &message);
    };

    class InvalidPeselChecksum : public AcademiaDataValidationError {
    public:
        InvalidPeselChecksum(const std::string &pesel, int sum);
    };

    class InvalidPeselLength : public AcademiaDataValidationError {
    public:
        InvalidPeselLength(const std::string &pesel, int length);
    };

    class InvalidPeselCharacter : public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(const std::string &pesel);
    };
}

#endif //JIMP_EXERCISES_PESEL_H
