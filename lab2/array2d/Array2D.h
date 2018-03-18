//
// Created by adrja on 08.03.2018.
//

#ifndef JIMP_EXERCISES_ARRAY2D_H
#define JIMP_EXERCISES_ARRAY2D_H

#include <iostream>

int **NewArray2D(int n_rows, int n_columns);
int **FillArray2D(int n_rows, int n_columns, int ** array);
void DeleteArray2D(int **array, int n_rows, int n_columns);
void PrintArray2D(int **array, int n_rows, int n_columns);

#endif //JIMP_EXERCISES_ARRAY2D_H
