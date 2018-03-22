//
// Created by adrja on 07.03.2018.
//

#include "ReverseString.h"

std::string StringReverse(std::string str){
    std::string buffer;

    if(str.length()==0){
        return "\0";
    }
    buffer = str.back() + StringReverse(str.substr(0, str.length() - 1));

    return buffer;
}
