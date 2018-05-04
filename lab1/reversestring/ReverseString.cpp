//
// Created by adrja on 07.03.2018.
//

#include "ReverseString.h"

std::string reverse(std::string str) {
    std::string buffer;

    if(str.length()==0){
        return "\0";
    }
    buffer = str.back() + reverse(str.substr(0, str.length() - 1));

    return buffer;
}
