//
//  problem25.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem25.hpp"

#include <iostream>
#include <cmath>

static const long double Phi = (1+sqrt(5))/2, phi = (1-sqrt(5))/2;
static const long double sqrt5 = sqrt(5);

void run_problem25()
{
    int i = 1;
    for (;logl((powl(Phi,i)-pow(phi,i))/sqrt5)/logl(10.0) < 999 ; i++) {
    }
    
    std::cout << i << "\n";
}