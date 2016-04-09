//
//  problem9.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem9.hpp"

#include <iostream>

void run_problem9()
{
    int p = 0;
    
    
    for (int a = 1; a < 334; a++) {
        for (int b = a + 1; b < 666; b++) {
            int c = 1000 - a - b;
            if (c > a && c > b) {
                if (c*c == a*a + b*b) {
                    p = a*b*c;
                }
            }
            else
                break;
            if (p) {
                break;
            }
        }
        if (p) {
            break;
        }
    }
    
    std::cout << p;
}
