//
// Created by adrja on 15.03.2018.
//

#include "Polybius.h"

std::string PolybiusCrypt(std::string message) {
    if(message.length() == 0) return "";

    char szachownica[5][5];
    char znak = 'a';

    for (auto &i : szachownica) {
        for (char &j : i) {
            if (znak == 'j') {
                ++znak;
            }
            j = znak;
            ++znak;
        }
    }

    std::string crypted;

    for (char l : message) {
        if(l =='j' || l == 'J') l='i';
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (szachownica[i][j] == l || szachownica[i][j] == 'a'-'A'+l) {
                    crypted += ('0'+(i + 1));
                    crypted += ('0'+(j + 1)) ;
                    break;
                }
            }
        }

    }
    return crypted;
}

std::string PolybiusDecrypt(std::string crypted) {

    char szachownica[5][5];
    char znak = 'a';

    for (auto &i : szachownica) {
        for (char &j : i) {
            if (znak == 'j') {
                ++znak;
            }
            j = znak;
            ++znak;
        }
    }

    std::string message;
    int char_code = 0;

    for (int k = 0; k < crypted.length(); ++k) {
        if (crypted[k] == ' ') {
            message += " ";
            continue;
        }
        char_code = 10 * (crypted[k] - '0') + crypted[k + 1] - '0';

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (char_code == (10 * (i + 1) + j + 1)) {
                    message += szachownica[i][j];
                    char_code = 0;
                }
            }
        }
        ++k;
    }
    return message;
}