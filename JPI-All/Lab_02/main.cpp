//
// Created by adrja on 10.03.2018.
//

#include "Lab_02.h"

int main(){
    std::cout<<CountLinesInFile("polski.txt")<<std::endl;
    std::cout<<LongestWordInFile("polski.txt")<<std::endl;
    SamePhaseStartedWordsInFile("polski.txt");
    return 0;
}