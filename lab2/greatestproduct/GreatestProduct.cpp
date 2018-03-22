//
// Created by adrja on 16.03.2018.
//

#include "GreatestProduct.h"

int max(int x1, int x2) {
    return x1 > x2 ? x1 : x2;
}

int GreatestProduct(const std::vector<int> &numbers, int k) {
    if (numbers.empty()) {
        return 0;
    }
    std::vector<int> new_vector(numbers);
    int result = 1;
    sort(new_vector.begin(), new_vector.end());

    if (k % 2 && new_vector[new_vector.size() - 1] <= 0) {
        for (int i = 1; i <= k; ++i) {
            result *= new_vector[new_vector.size() - 1];
            new_vector.pop_back();
        }
    } else {
        int positive_mul, negative_mul;
        while (k > 1) {
            negative_mul = new_vector[0] * new_vector[1];
            positive_mul = new_vector[new_vector.size() - 1] * new_vector[new_vector.size() - 2];

            if (negative_mul > positive_mul) {
                result *= negative_mul;
                new_vector.erase(new_vector.begin(), new_vector.begin() + 1);
            } else {
                result *= positive_mul;
                new_vector.erase(new_vector.end() - 1, new_vector.end());
            }
            k -= 2;
        }
    }

    if (k == 1) result *= max(new_vector[new_vector.size() - 1], new_vector[new_vector.size() - 2]);

    return result;
}