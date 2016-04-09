//
//  problem2.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem2.hpp"



#include <iostream>
void run_problem2()
{
    int sum = 2;
    int a = 1, b = 2;
    for (; ; )
    {
        a += b;
        if (a > 4000000) {
            break;
        }
        if (a%2 == 0) {
            sum += a;
        }
        b += a;
        if (b > 4000000) {
            break;
        }
        if (b%2 == 0) {
            sum += b;
        }
    }
    std::cout << sum;
}
