//
// Created by adrja on 16.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

class TextPool {

//    Rule of Five (z usuniętą możliwością kopiowania)
//    domyślny konstruktor
//    konstruktor z listą inicjalizacyjną

    std::experimental::string_view Intern(const std::string &str);

    size_t StoredStringCount() const;

};


#endif //JIMP_EXERCISES_TEXTPOOL_H
