//
//  problem206.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem206.hpp"

#include <iostream>

//=========================== Problem 206 ===========================
//Title: Concealed Square
/*
 Start date: 4/4/2016
 Finish date: 4/4/2016
 
 Description:
 Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
 where each “_” is a single digit.
 */

void run_problem206()
{
    long long sq, i;
    
    for (i = 1010101010; i < 1389026623; i++) {
        sq = i*i;
        if (sq % 10 == 0) {
            sq /= 100;
            if (sq % 10 == 9) {
                sq /= 100;
                if (sq % 10 == 8) {
                    sq /= 100;
                    if (sq % 10 == 7) {
                        sq /= 100;
                        if (sq % 10 == 6) {
                            sq /= 100;
                            if (sq % 10 == 5) {
                                sq /= 100;
                                if (sq % 10 == 4) {
                                    sq /= 100;
                                    if (sq % 10 == 3) {
                                        sq /= 100;
                                        if (sq % 10 == 2) {
                                            std::cout << i << "\n";
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
