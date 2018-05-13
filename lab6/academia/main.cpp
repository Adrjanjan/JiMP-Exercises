//
// Created by adrja on 21.04.2018.
//
#include <cstdlib>
#include <iostream>
#include "StudentRepository.h"

using namespace academia;

int main() {

    std::string id, first_name, surname, program;
    size_t year;
    StudentRepository repository;
    bool read = true;

    while (read) {

        std::cout << "Podaj ID studenta:\n";
        std::cin >> id;

        std::cout << "Podaj imie studenta:\n";
        std::cin >> first_name;

        std::cout << "Podaj nazwisko studenta:\n";
        std::cin >> surname;

        std::cout << "Podaj program studenta:\n";
        std::cin >> program;

        std::cout << "Podaj rok nauki studenta:\n";
        std::cin >> year;

        try {
            academia::Student(id, first_name, surname, program, year);
        } catch (InvalidNameSurname &inv_name_sur) {
            std::cout << inv_name_sur.what();
            continue;
        } catch (InvalidNameCharacters &inv_name_char) {
            std::cout << inv_name_char.what();
            continue;
        } catch (InvalidAge &inv_age) {
            std::cout << inv_age.what();
            continue;
        } catch (InvalidProgram &inv_prog) {
            std::cout << inv_prog.what();
            continue;
        }

        std::cout << "Press Enter to continue entering students to repository." << std::endl;
        read = false;
        if (getchar() == '\n') {
            read = true;
        }
    }


}
