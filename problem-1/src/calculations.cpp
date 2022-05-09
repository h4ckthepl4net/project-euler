#include "calculations.h"
#include <iostream>

long double calculations::calcSum(arguments::range range) {
    long double result = 0;
    for(long long num = range.first; num < range.      second; num++) {
        if(num % 5 == 0 || num % 3 == 0) {
            result += num;
        }
    }
    return result;
}
