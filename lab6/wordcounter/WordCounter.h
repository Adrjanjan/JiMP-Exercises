//
// Created by adrja on 21.04.2018.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "Word.h"
#include "Counts.h"

namespace datastructures {
    class WordCounter {

    public:
        WordCounter();

        WordCounter(const std::initializer_list<Word> &initializer_list);

        Counts DistinctWords();

        Counts TotalWords();

        std::set<Word> Words();

        Counts operator[](const std::string &key);

        Counts operator[](const datastructures::Word &key);

    private:
        std::map<Word, Counts> counter_;
    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
