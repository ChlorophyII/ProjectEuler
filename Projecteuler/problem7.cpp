//
//  problem7.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem7.hpp"

#include <iostream>
#include <math.h>

bool isPrime(long a, long p[], int num);

void run_problem7()
{
    long p[10001];
    int i = 0;
    for (long j = 2; i < 10001; j++)
    {
        if (isPrime(j, p, i))
        {
            p[i] = j;
            i++;
        }
    }
    std::cout << p[10000] << "\n";
}

bool isPrime(long a, long p[], int num)
{
    for (int i = 0; i < num; i++) {
        if (a%p[i] == 0) {
            return false;
        }
    }
    return true;
    
}