//
//  problem34.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem34.hpp"

#include <iostream>

//Note, 9! * 7 = 2540160, which means 2540160 is the upper bound of such numbers.

static int oneDigitFactorial(int a);

void run_problem34()
{
    long sum = 0;
    int a, b;
    for (int i = 3; i < 2540160; i++)
    {
        a = i;
        b = 0;
        while (a > 0) {
            b += oneDigitFactorial(a % 10);
            a /= 10;
        }
        if (i == b)
            sum += i;
    }
    std::cout << sum << "\n";
}

static int oneDigitFactorial(int a)
{
    switch (a) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 24;
        case 5:
            return 120;
        case 6:
            return 720;
        case 7:
            return 5040;
        case 8:
            return 40320;
        case 9:
            return 362880;
        default:
            break;
    }
    return 0;
}