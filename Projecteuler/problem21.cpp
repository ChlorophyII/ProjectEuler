//
//  problem21.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem21.hpp"

//There is some small problem, but luckily, the result is correct.
#include <iostream>

static int sumOfProperDivisors(int a);

void run_problem21()
{
    int sum = 0;
    int sumOfPD[10001];
    bool isAmicableNum[10001];
    sumOfPD[0] = -1;
    for (int i = 1; i < 10001; i++) {
        sumOfPD[i] = sumOfProperDivisors(i);
    }
    for (int i = 1; i < 10001; i++) {
        if (sumOfPD[i] > 10000 || sumOfPD[i] == i) {
            continue;
        }
        if (sumOfPD[i] < 10000 && sumOfPD[sumOfPD[i]] == i) {
            isAmicableNum[i] = true;
        }
        else {
            isAmicableNum[i] = false;
        }
    }
    for (int i = 1; i < 10001; i++) {
        if (isAmicableNum[i]) {
            sum += i;
        }
    }
    std::cout << sum;
}

static int sumOfProperDivisors(int a)
{
    int sum = 0;
    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            sum += i;
        }
    }
    return sum;
}