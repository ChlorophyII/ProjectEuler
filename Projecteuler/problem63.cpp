//
//  problem63.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem63.hpp"

#include <iostream>
#include <cmath>

//I thought I was drunken or I was extremely sleepy when I wrote this mess.

void run_problem63()
{
    //Note that even using long long, it will overflow.
    int cnt = 0;
    double lb, ub, p;
    for (int i = 0; i < 25; i++) {
        for (int j = 1; j < 10; j++) {
            lb = pow(10, i-1) - 1;
            ub = pow(10, i);
            p = pow(j, i);
        }
    }
    for (int i = 1; i < 10; i++) {
        for (int j = -1; j > -10; j--) {
            ub = -(pow(10, i-1) - 1);
            lb = -pow(10, i);
            p = pow(j, i);
        }
    }
    cnt = 0;
    for (int i = 1; i < 25; i++) {
        cnt += 10 - ceil(pow(10, 1 - 1.0/i));
    }
    std::cout << cnt << "\n";
}
