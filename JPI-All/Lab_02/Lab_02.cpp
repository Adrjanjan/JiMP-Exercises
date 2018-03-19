//
// Created by adrja on 10.03.2018.
//

#include "Lab_02.h"

int CountLinesInFile(std::string file_name) {

    std::ifstream file_in;
    file_in.open(file_name, std::ios::in);

    if (file_in.good()) {
        int how_many = 0;
        std::string buffer;
        while (!file_in.eof()) {
            ++how_many;
            file_in >> buffer;
        }

        file_in.close();
        return how_many;
    } else {
        std::cout << "Nie udało się otworzyć pliku :C" << std::endl;
        return -1;
    }
}

std::string LongestWordInFile(std::string file_name) {

    std::ifstream file_in;
    file_in.open(file_name, std::ios::in);

    if (file_in.good()) {
        unsigned long max_word_len = 0;
        std::string longest_word, buffer;
        while (!file_in.eof()) {
            file_in >> buffer;
            if (buffer.length() > max_word_len) {
                max_word_len = buffer.length();
                longest_word = buffer;
            }
        }

        file_in.close();
        return longest_word;
    } else {
        std::cout << "Nie udało się otworzyć pliku :C" << std::endl;
        return "";
    }
}

void SameLetterStartedWordsInFile(std::string file_name) {

    std::ifstream file_in;
    file_in.open(file_name, std::ios::in);

    if (file_in.good()) {
        char c{};
        std::string buffer;

        std::cout<<"Podaj znak do znalezienia innych słów\n zaczynających się tą samą literą.\n";
        std::cin>>c;

        while (!file_in.eof()) {
            file_in >> buffer;
            if (buffer[0] == c) {
                std::cout << buffer << std::endl;
            }
        }

        file_in.close();

    } else {
        std::cout << "Nie udało się otworzyć pliku :C" << std::endl;
    }
}

void SamePhaseStartedWordsInFile(std::string file_name) {

    std::ifstream file_in;
    file_in.open(file_name, std::ios::in);

    if (file_in.good()) {
        std::string buffer, phase;

        std::cout << "Podaj wyrażeni do znalezienia innych słów\n zaczynających się tak samo:.\n";
        std::cin >> phase;

        while (!file_in.eof()) {
            file_in >> buffer;
            if (buffer.find(phase, 0) == 0) {
                std::cout << buffer << std::endl;
            }
        }

        file_in.close();

    } else {
        std::cout << "Nie udało się otworzyć pliku :C" << std::endl;
    }
}