//
//  problem5.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem5.hpp"

#include <iostream>

bool isPrime(int a);

void run_problem5()
{
    int primes[8][2];
    int idx = 0;
    for (int i = 1; i < 20; i++) {
        if (isPrime(i)) {
            primes[idx][0] = i;
            primes[idx][1] = 1;
            idx++;
        }
    }
    
    for (int i = 11; i < 21; i++) {
        for (int j = 0; j < 8; j++) {
            int m = i, n = 0;
            while (m % primes[j][0] == 0) {
                n++;
                m /= primes[j][0];
            }
            if (n > primes[j][1])
                primes[j][1] = n;
        }
    }
    
    int product = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < primes[i][1]; j++) {
            product *= primes[i][0];
        }
    }
    std::cout << product;
}

bool isPrime(int a)
{
    if (a < 2) {
        return false;
    }
    else if (a == 2) {
        return true;
    }
    else if (a % 2 == 0)
    {
        return false;
    }
    else
    {
        for (int p = 3; p < a; p += 2) {
            if (a % p == 0) {
                return false;
            }
        }
    }
    return true;
}