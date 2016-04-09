//
//  problem30.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem30.hpp"

#include <iostream>
#include <cmath>

void run_problem30()
{
    int a, b, c, d, e, f;
    double m;
    long sum = 0;
    for (int i = 2; i < 1000000; i++) {
        a = i % 10;
        b = (i / 10) % 10;
        c = (i / 100) % 10;
        d = (i / 1000) % 10;
        e = (i / 10000) % 10;
        f = (i / 100000) % 10;
        m = pow(a, 5) + pow(b, 5) + pow(c, 5) + pow(d, 5) + pow(e, 5) + pow(f, 5);
        if (m < i + 0.5 && m > i - 0.5) {
            sum += i;
        }
    }
    std::cout << sum << "\n";
}
