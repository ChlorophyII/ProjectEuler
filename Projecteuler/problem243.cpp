//
//  problem243.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem243.hpp"

#include <iostream>
#include <fstream>
#include <cmath>

static int locateGreatestPrime(int a, int primes[]);

void run_problem243()
{
    using namespace std;
    
    int *primes = (int *)malloc(10008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 1000000; i++) {
        fin >> primes[i];
    }
    fin.close();
    
    double bound = 15499.0/94744.0;
    
    int i;
    double a, b;
    for (i = 3;;i++)
    {
        a = 1.0, b = 1.0;
        for (int j = 0; j < i; j++) {
            a *= (primes[j] - 1.0);
            b *= primes[j];
        }
        if (a/(b - 1.0) < bound) {
            break;
        }
    }
    i--;
    a /= primes[i] - 1;
    b /= primes[i];
    
    for (int i = 4; i < primes[i]; i++) {
        if (locateGreatestPrime(i, primes) == i) {
            continue;
        }
        if ((a * i)/(b * i - 1.0) < bound) {
            long result = long(b * i);
            cout << "The final result is: " << result << "\n";
            break;
        }
    }
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