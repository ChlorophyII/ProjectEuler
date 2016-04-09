//
//  problem23.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem23.hpp"

#include <iostream>

static bool isAbundant(int a);
static bool isSumOfAbdNumbers(int a, bool *isAbd);

void run_problem23()
{
    bool isAbd[28123];
    for (int i = 1; i < 28123; i++) {
        isAbd[i] = isAbundant(i);
    }
    long sum = 0;
    for (int i = 1; i < 28123; i++) {
        if (!isSumOfAbdNumbers(i, isAbd)) {
            sum += i;
        }
    }
    std::cout << sum << "\n";
}

static bool isAbundant(int a)
{
    int sum = 0;
    for (int i = 1; i <= a/2; i++) {
        if (a % i == 0) {
            sum += i;
        }
    }
    if (sum > a)
        return true;
    else
        return false;
}

static bool isSumOfAbdNumbers(int a, bool *isAbd)
{
    for (int i = 1; i <= a/2 ; i++) {
        if (isAbd[i] && isAbd[a-i]) {
            return true;
        }
    }
    return false;
}