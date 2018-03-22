//
// Created by adrja on 16.03.2018.
//

#include "XorCypherBreaker.h"


std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<std::string> &dictionary) {

    int counts_in_dict = 0;
    std::string tmp_key, key, tmp;
    std::vector<std::string> found_words;
    //key innit
    for (int i = 0; i < key_length; ++i) key += "a";
    key = "lol";

    while (counts_in_dict < 10) {
        counts_in_dict = 0;
        found_words.clear();
        for (int i = 0; i < cryptogram.size(); ++i) {
            tmp += char(int(cryptogram[i]) ^ key[i % key_length]);
            if (tmp.end()[-1] == ' ') {
                tmp.pop_back();
                found_words.push_back(tmp);
                tmp.erase();
            }
        }
        for (const auto &word: found_words) {
            if (find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) {
                ++counts_in_dict;
            }
        }
        tmp_key = key;
        ++key.end()[-1];
        for (int i = key_length - 1; i >= 0; --i) {
            if (key[i] > 'z') {
                key[i] = static_cast<char>(key[i] % ('z' - 'a' - 1) + 'a' - 3);
                ++key[i - 1];
            }
        }
    }
    return tmp_key;
}

