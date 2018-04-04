//
// Created by adrja on 02.04.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEURL_H
#define JIMP_EXERCISES_SIMPLEURL_H

#include <string>
#include <regex>
#include <cstdint>

namespace nets {

    class SimpleUrl {
    public:
        explicit SimpleUrl(std::string url);

        std::string Login() const;

        std::string Host() const;

        std::string Path() const;

        uint16_t Port() const;

        std::string Scheme() const;

        std::string Query() const;

        std::string Fragment() const;

    private:
        enum CapturingGroups {
            SCHEME = 1, LOGIN = 3, HOST = 5, PORT = 7, PATH = 9, QUERY = 11, FRAGMENT = 13
        };
        std::string url_;
        std::regex url_pattern_{
                R"(([a-z\+\-\.]*)?\:(([a-z]*)\@|(\/\/))?([a-z0-9\.\-]*)?(:(\d*))?(\/?([^?#]*))(\?(.*))?(\#(.*))?)"};
        std::smatch url_matches_;
    };
}

#endif //JIMP_EXERCISES_SIMPLEURL_H
