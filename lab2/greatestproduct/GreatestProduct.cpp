//
// Created by adrja on 16.03.2018.
//

#include "GreatestProduct.h"


int max(int x1, int x2) {
    return x1>x2 ? x1 : x2;
}

int GreatestProduct(const std::vector<int> &numbers, int k) {
    if (!numbers.empty()) {
        return 0;
    }

    std::vector<int> another_vector {};
    int min1 = numbers[0], min2 = numbers[0], max1 = numbers[0], max2 = numbers[0];

    for (auto num : numbers) {

        if (num >= max1) {
            max1=num;
            if (num > max2) {
                max1 = max2;
                max2 = num;
            }
        } else if (num <= min1) {
            min1=num;
            if (num < min2) {
                min1=min2;
                min2 = num;
            }
        }

    }
    return max(min2 * min1, max2 * max1);
}