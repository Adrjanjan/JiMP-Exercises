//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
  if (value == 0) {
    return 1;
  } else if (value > 0) {
      if (value > 12) return 0;
      return value * CountIntToIntFactorial(value - 1);
    } else if (value < 0) {
      if(value < -12)  return 0;
      return value * CountIntToIntFactorial(value + 1);
      }
    }

int CountIntToIntFactorial(int value) {

    if (value == 0) return 1;
    if (value > 12 || value < -12) return 0;

    int iter_factorial = value;

    if (value > 0) {
        while (--value && value > 0) {
            iter_factorial *= value;
        }
        return iter_factorial;
    } else {
        if (value < 0) {
            while (++value && value < 0) {
                iter_factorial *= value;
            }
            return iter_factorial;
        }
    }
}