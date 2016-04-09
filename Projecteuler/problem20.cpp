//
//  problem20.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem20.hpp"

#include <iostream>
#include "BIGNUM.hpp"
//Set __BIGNUMLENGTH > 200

void run_problem20()
{
    BIGNUM a;
    a.add(1);
    for (int i = 1; i < 101; i++) {
        a.mult(i);
        //        a.disp();
        //        std::cout << "\n" << i << "\n\n";
    }
    int sum = 0;
    a.disp();
    for (int i = 0; i < a.getNumDigits(); i++) {
        sum += a.getDigit(i);
    }
    std::cout << "\n" << sum << "\n";
}