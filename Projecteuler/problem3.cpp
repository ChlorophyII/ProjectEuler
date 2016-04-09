//
//  problem3.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem3.hpp"
#include <iostream>

static int largestPrimeFactor(long long a);

void run_problem3()
{
    std::cout << largestPrimeFactor(600851475143) << "\n";
}

static int largestPrimeFactor(long long a)
{
    int factors[64];
    int i = 0;
    int p = 3;
    
    while(a%2 == 0)
    {
        factors[i] = 2;
        i++;
        a = a/2;
    }
    while (a != 1)
    {
        while (a%p == 0)
        {
            factors[i] = p;
            i++;
            a = a/p;
        }
        p += 2;
    }
    return factors[i-1];
}