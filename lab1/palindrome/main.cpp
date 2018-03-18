//
// Created by adrja on 07.03.2018.
//

#include <iostream>
#include "Palindrome.h"

int main(){

    std::cout<<"Czy chcesz sprawdzic czy slowo jest palindromem?\n Wciśnij:\n\tT - tak\n\tN - nie.\n";
    char C;
    bool good_char = true;
    std::cin>>C;

    while(good_char) {
        good_char = false;

        switch (C) {

            case ('t'): {
            }
            case ('T'): {
                std::string word;
                std::cout << "Podaj slowo: ";
                std::cin >> word;
                std::cout << '\n';
                if (is_palindrome(word)) {
                    std::cout << "Słowo \"" << word << "\" jest palindromem!" << std::endl;
                } else {
                    std::cout << "Słowo \"" << word << "\"  nie jest palindromem!" << std::endl;
                }
                break;
            }

            case ('n'): {
            }
            case ('N'): {
                std::cout << "Nie, to nie. \n\t\t Żegnam!" << std::endl;

            }
            default:
                std::cout << "Podano zły znak!\nWstaw nowy!" << std::endl;
                good_char = true;
                std::cin>>C;
                break;
        }
    }

  return 0;
}