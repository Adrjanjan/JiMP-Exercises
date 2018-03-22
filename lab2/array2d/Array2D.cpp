//
// Created by adrja on 08.03.2018.
//

#include "Array2D.h"

int **NewArray2D(int n_rows, int n_columns) {
    if(n_columns <=0 || n_rows <=0) {
//        std::cout << "Pusta tablica";
        return nullptr;
    }

    int **tab = new int *[n_rows];
    int k = 0;

    for (int i = 0; i < n_rows; ++i) {
        tab[i] = new int[n_columns];
        for (int j = 0; j < n_columns; ++j) {
            tab[i][j] = k;
        }
    }
    return tab;
}

int** FillArray2D(int n_rows, int n_columns, int ** array) {
    if(array == nullptr) {
//        std::cout << "Pusta tablica";
        return nullptr;
    }

    int k = 0;

    for (int i = 0; i < n_rows; ++i) {
        array[i] = new int[n_columns];
        for (int j = 0; j < n_columns; ++j) {
            array[i][j] = ++k;
        }
    }
    return array;
}

void PrintArray2D(int** array, int n_rows, int n_columns) {
    if (array == nullptr) {
//        std::cout << "Pusta tablica";
        return;
    }
    for (int i = 0; i < n_rows; ++i) {

        for (int j = 0; j < n_columns; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DeleteArray2D(int **array, int n_rows, int n_columns) {
    if (array == nullptr) {
        return;
    }
    for (int i = 0; i < n_rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}


