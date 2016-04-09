//
//  problem6.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem6.hpp"
#include <iostream>

void run_problem6()
{
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < 101; i++)
    {
        sum1 += i*i;
        sum2 += i;
    }
    
    std::cout << sum2*sum2 - sum1 << "\n";
}