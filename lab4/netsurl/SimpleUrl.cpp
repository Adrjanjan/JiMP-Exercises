//
// Created by adrja on 02.04.2018.
//

#include "SimpleUrl.h"
#include <utility>

nets::SimpleUrl::SimpleUrl(std::string url) {
    url_ = std::move(url);
    std::regex_match(url_, url_matches_, url_pattern_);
}

std::string nets::SimpleUrl::Scheme() const {
    return url_matches_[SCHEME].str();
}

std::string nets::SimpleUrl::Login() const {
    return url_matches_[LOGIN].str();
}

std::string nets::SimpleUrl::Host() const {
    return url_matches_[HOST].str();
}

uint16_t nets::SimpleUrl::Port() const {

    if (url_matches_[PORT].str() == "") {
        if (url_matches_[SCHEME].str() == "https") return 443;
        if (url_matches_[SCHEME].str() == "http") return 80;
        if (url_matches_[SCHEME].str() == "ftp") return 22;
        return 0;
    }

    return std::stoi(url_matches_[PORT].str());
}

std::string nets::SimpleUrl::Path() const {
    return url_matches_[PATH].str();
}

std::string nets::SimpleUrl::Query() const {
    return url_matches_[QUERY].str();
}

std::string nets::SimpleUrl::Fragment() const {
    return url_matches_[FRAGMENT].str();
}

