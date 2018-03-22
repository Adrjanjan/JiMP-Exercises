//
// Created by adrja on 07.03.2018.
//

#include "MultiplicationTable.h"


void MultiplicationTable(int tab[][10]){

    for(int i = 1; i<=10; ++i){
        for(int j =1; j<=10; ++j){
            tab[i-1][j-1] = i*j;
            std::cout<<tab[i-1][j-1]<<" ";
        }
        std::cout<<"\n";
    }


}
