//
//  problem28.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem28.hpp"

#include <iostream>

void run_problem28()
{
    long a = 1, sum = 1;
    for (int i = 2; i <= 1000; i += 2) {
        a += i;
        sum += a;
        a += i;
        sum += a;
        a += i;
        sum += a;
        a += i;
        sum += a;
    }
    std::cout << sum << "\n";
}