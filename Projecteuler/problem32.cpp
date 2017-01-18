//
//  problem32.cpp
//  Projecteuler
//
//  Created by Shi Yue on 30/5/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem32.hpp"

bool isPandigital(int a);

void generatePandigitalNumList(int );

void run_problem32()
{
    
}

bool isPandigital(int a)
{
    bool digit[10];
    short b;
    for (short i = 1; i < 10; i++) {
        digit[i] = 0;
    }
    while (a > 0) {
        b = a % 10;
        if (digit[b]) {
            return false;
        }
        else {
            digit[b] = true;
            a /= 10;
        }
    }
    return true;
}