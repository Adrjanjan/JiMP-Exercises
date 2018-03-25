//
// Created by adrja on 22.03.2018.
//

#include "TinyUrl.h"

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init() {

        std::unique_ptr<TinyUrlCodec> codec_structure(new TinyUrlCodec);
        codec_structure->state = {'0', '0', '0', '0', '0', '0'};
        codec_structure->urls = {};
        return std::move(codec_structure);
    }

    void NextHash(std::array<char, 6> *state) {
        ++state->end()[-1];
        for (int i = 6 - 1; i >= 0; --i) {
            if (state->at(i) == '9' + 1) {
                state->at(i) = static_cast<char>('A');
            } else if (state->at(i) == 'Z' + 1) {
                state->at(i) = static_cast<char>('a');
            } else if (state->at(i) == 'z' + 1) {
                state->at(i) = static_cast<char>('0');
                ++state->at(i - 1);
            }
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {

        std::string hash;
        NextHash(&(*codec)->state);
        for (const auto i: (*codec)->state) {
            hash += i;
        }
        (*codec)->urls.emplace(hash, url);
        return hash;
    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {

        for (const auto &i: codec->urls) {
            if (i.first == hash) {
                return i.second;
            }
        }
        return "";
    }
}