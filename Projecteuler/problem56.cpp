//
//  problem56.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem56.hpp"

#include <iostream>
#include "BIGNUM.hpp"
//Set __BIGNUMLENGTH = 200

void run_problem56()
{
    int maxDigitalSum = 0;
    for (int a = 1; a < 100; a++) {
        for (int b = 1; b < 100; b++) {
            BIGNUM bn;
            bn.add(a);
            bn.pow(b);
            maxDigitalSum = (maxDigitalSum > bn.getDigitSum()) ? maxDigitalSum:bn.getDigitSum();
        }
    }
    std::cout << maxDigitalSum << "\n";
}