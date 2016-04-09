//
//  problem26.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem26.hpp"

#include <iostream>

static int reciprocalCycleLength(int a);

void run_problem26()
{
    int d = 0, length = 0;
    for (int i = 1; i < 1000; i++) {
        if (reciprocalCycleLength(i) > length) {
            length = reciprocalCycleLength(i);
            d = i;
        }
    }
    std::cout << "d = " << d << "\n";
}

static int reciprocalCycleLength(int a)
{
    int dividend = 1;
    for (int i = 0; i < 50; i++) {
        while (dividend < a) {
            dividend *= 10;
        }
        int j;
        for (j = 0; dividend - (j+1) * a >= 0; j++) {
        }
        dividend -= j * a;
        if (dividend == 0) {
            return 0;
        }
    }
    int r = dividend;
    int cnt = 0;
    while (cnt == 0 || r != dividend) {
        if (dividend < a) {
            dividend *= 10;
        }
        while (dividend < a) {
            dividend *= 10;
            cnt++;
        }
        int j;
        for (j = 0; dividend - (j+1) * a >= 0; j++) {
        }
        dividend -= j * a;
        cnt++;
    }
    return cnt;
}