//
// Created by adrja on 05/05/2018.
//

#include "Pesel.h"

academia::Pesel::Pesel(std::string pesel) {
    if (validatePESEL(pesel)) {
        pesel_ = pesel;
    }

/*
    try {
        if (validatePESEL(pesel)) {
            pesel_ = pesel;
        }
    } catch (InvalidPeselLength &inv_len) {
        inv_len.what();
    } catch (InvalidPeselCharacter &inv_char) {
        inv_char.what();
    } catch (InvalidPeselChecksum &inv_sum) {
        inv_sum.what();
    }
*/
}


bool academia::Pesel::validatePESEL(const std::string pesel) {
    if (pesel.length() != 11) throw InvalidPeselLength(pesel, pesel.length());

    int tab[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int sum = 0;

    for (int i = 0; i < pesel.length(); ++i) {
        if (pesel[i] < '0' || pesel[i] > '9') throw InvalidPeselCharacter(pesel);
        sum += tab[i] * (pesel[i] - '0');
    }
    if (sum % 10 != 0) throw InvalidPeselChecksum(pesel, sum);
    return true;
}

academia::AcademiaDataValidationError::AcademiaDataValidationError(const std::string &message) : invalid_argument(
        message) {}

academia::InvalidPeselChecksum::InvalidPeselChecksum(const std::string &pesel, int sum) : AcademiaDataValidationError(
        "Invalid PESEL(" + pesel + ") checksum: " + std::to_string(sum)) {}

academia::InvalidPeselLength::InvalidPeselLength(const std::string &pesel, int length) : AcademiaDataValidationError(
        "Invalid PESEL(" + pesel + ") length: " + std::to_string(length)) {}

academia::InvalidPeselCharacter::InvalidPeselCharacter(const std::string &pesel) : AcademiaDataValidationError(
        "Invalid PESEL(" + pesel + ") character set") {}
