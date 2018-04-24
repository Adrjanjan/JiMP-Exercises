//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>

namespace datastructures {

    class Word {
    public:
        Word();

        Word(std::string str);

        void Set(std::string str);

        std::string Get();

        friend bool operator==(const Word &l, const Word &r);

        friend bool operator>(const Word &l, const Word &r);

        friend bool operator<(const Word &l, const Word &r);

    private:
        std::string word_;
    };

    bool operator==(const Word &l, const Word &r);

    bool operator>(const Word &l, const Word &r);

    bool operator<(const Word &l, const Word &r);
}

#endif //JIMP_EXERCISES_WORD_H
