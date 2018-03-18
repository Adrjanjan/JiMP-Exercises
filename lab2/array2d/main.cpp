//
// Created by adrja on 08.03.2018.
//

#include "Array2D.h"

int main()
{
    std::cout<<"Podaj wymiary tablicy\n";
    int row =0, col =0;
    std::cin>>row >>col;
    int tabliczka[4][4] {};

    int** tablica = NewArray2D(row, col);
    PrintArray2D(tablica, row, col);
    DeleteArray2D(tablica, row, col);
}