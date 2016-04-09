//
//  problem10.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem10.hpp"
#include <ctime>
#include <iostream>
#include <math.h>

static bool isPrime(int a, int p[], int num);

void run_problem10()
{
    clock_t start = clock();
    int  p[170000];
    long sum = 2;
    int j;
    p[0] = 2;
    int i = 1;
    for (j = 3; i < 170000; j += 2)
    {
        if (j > 2000000) {
            std::cout << sum << "\n" << double(clock()-start)/CLOCKS_PER_SEC;
            exit(9);
        }
        if (isPrime(j, p, i))
        {
            p[i] = j;
            sum += j;
            i++;
        }
    }
    for (; j < 2000000; j++) {
        if (isPrime(j, p, 170000)) {
            sum += j;
        }
    }
    std::cout << sum << "\n" << double(clock()-start)/CLOCKS_PER_SEC << "\n";
}

static bool isPrime(int a, int p[], int num)
{
    for (int i = 0; i < num; i++) {
        if (a%p[i] == 0) {
            return false;
        }
    }
    return true;
}


/*
#include <ctime>
#include <iostream>
#include <math.h>

static const int LIMIT = 2000000;
static const int SQRTLIMIT = sqrt(LIMIT) + 1;

void run_problem10()
{
    clock_t start = clock();
    bool sieve[LIMIT+1];
    for (int i = 0; i <= LIMIT; i++) {
        sieve[i] = false;
    }
    for (int i = 4; i <= LIMIT; i +=2) {
        sieve[i] = true;
    }
    for (int i = 3; i < SQRTLIMIT; i+=2) {
        if (!sieve[i]) {
            for (int j = i*i; j < LIMIT; j += i) {
                sieve[j] = true;
            }
        }
    }
    long long sum = 2;
    for (int i = 3; i <= LIMIT; i += 2) {
        if (!sieve[i]) {
            sum += i;
        }
    }
    std::cout << sum << "\n" << double(clock()-start)/CLOCKS_PER_SEC;
}
*/