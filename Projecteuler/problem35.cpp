//
//  problem35.cpp
//  Projecteuler
//
//  Created by Shi Yue on 21/9/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem35.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

static int locateGreatestPrime(int a, int primes[]);

bool isCircularPrime(int n, int* primes);

void run_problem35()
{
    using namespace std;
    int *primes = (int *)malloc(100008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 100008; i++) {
        fin >> primes[i];
    }
    fin.close();
    
    int counter = 0;
    
    for (int i = 0; primes[i] < 1000000; i++) {
        if (isCircularPrime(primes[i], primes)) {
            counter++;
        }
    }
    std::cout << counter << "\n";
}

bool isCircularPrime(int n, int* primes)
{
    int m = n;
    int digits = ceil(log10(n));
    for (int i = 0; i < digits; i++) {
        m = m / 10 + (m % 10) * (int)pow(10, digits - 1);
        if (m != primes[locateGreatestPrime(m, primes)]) {
            return false;
        }
    }
    return true;
}

static int locateGreatestPrime(int a, int primes[])
{
    //return i, where primes[i] <= a;
    int i = a / log(a);
    while (primes[i] < a) {
        i++;
    }
    while (primes[i] > a) {
        i--;
    }
    return i;
}