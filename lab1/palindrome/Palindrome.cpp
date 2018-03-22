//
// Created by adrja on 07.03.2018.
//

#include "Palindrome.h"

bool is_palindrome(std::string str){

    unsigned long int i=0, j = str.length()-1;

    while( i < str.length() / 2){
        if(str[i++] != str[j--]){
            return false;
        }
    }
    return true;
}
