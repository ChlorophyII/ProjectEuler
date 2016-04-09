//
//  problem4.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem4.hpp"
#include <iostream>

bool isPalindrome(long long a);

void run_problem4()
{
    int max = 0;
    for (int i = 999; i > 800; i--) {
        for (int j = 999; j > 800; j--) {
            if (isPalindrome(i*j)) {
                if (i * j > max)
                    max = i * j;
            }
        }
    }
    std::cout << max << "\n";
}

bool isPalindrome(long long a)
{
    int digits[21] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i;
    for ( i = 0; a != 0; i++) {
        digits[i] = a % 10;
        a /= 10;
    }
    for ( i = 20; digits[i] == 0; i--) {
    }
    for (int j = 0; j < (i+1)>>1; j++) {
        if (digits[j] != digits[i-j]) {
            return false;
        }
    }
    return true;
}