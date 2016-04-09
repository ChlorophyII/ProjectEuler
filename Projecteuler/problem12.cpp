
//
//  problem12.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem12.hpp"

#include <iostream>
#include <cmath>

static void fillInDivisors(int divisors[], int num);

void run_problem12()
{
    int divisors[1000];
    int add = 1, num = 0;
    
    for (int i = 0; i < 1000; i++) {
        divisors[i] = 0;
    }
    
    while (1) {
        num += add;
        fillInDivisors(divisors, num);
        add++;
        if (divisors[499] != 0)
        {
            break;
        }
    }
    
    std::cout << num << "\n";
}

static void fillInDivisors(int divisors[], int num)
{
    int j = 0;
    if (pow(int(sqrt(num)),2) == num)
    {
        divisors[j++] = sqrt(num);
    }
    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0) {
            divisors[j++] = i;
            divisors[j++] = num/i;
        }
    }
}