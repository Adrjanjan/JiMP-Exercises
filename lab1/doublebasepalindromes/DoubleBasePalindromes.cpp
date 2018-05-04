//
// Created by adrja on 07.03.2018.
//

#include "DoubleBasePalindromes.h"
#include "Palindrome.h"

std::string int_to_binary(int number){

    std::string binary = "";

    while(number > 0){
        binary = std::to_string(number % 2) + binary;
        number /=2;
    }
    return binary;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){

    std::stringstream ss;
    std::string number_as_string;
    uint64_t sum = 0;

    while(max_vaule_exculsive > 0){

        if(is_palindrome(std::to_string(max_vaule_exculsive)) && is_palindrome(int_to_binary(max_vaule_exculsive))){
            sum+=max_vaule_exculsive;
        }
        --max_vaule_exculsive;

    }
    return sum;
}
