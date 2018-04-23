//
// Created by adrja on 16.04.2018.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool {
    class TextPool {

//    Rule of Five (z usuniętą możliwością kopiowania)
//    domyślny konstruktor
//    konstruktor z listą inicjalizacyjną
    public:
        TextPool();

        TextPool(TextPool &&other);

        TextPool(const std::initializer_list<std::experimental::string_view> &pool);

        TextPool &operator=(TextPool &&other);

        //zwraca uchwyt (iterator) do łańcucha z pool_ jeżeli juz tam jest lub dodaje go i zwraca nowy, jeżeli nie ma
        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::set<std::experimental::string_view> pool_;
    };
}

#endif //JIMP_EXERCISES_TEXTPOOL_H
