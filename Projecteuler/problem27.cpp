//
//  problem27.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem27.hpp"

#include <iostream>
#include <fstream>
#include <cmath>

int locateGreatestPrime(int a, int primes[]);

void run_problem27()
{
    using namespace std;
    int *primes = (int *)malloc(100008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 100008; i++) {
        fin >> primes[i];
    }
    fin.close();
    
    int limit = locateGreatestPrime(1000, primes);
    
    int product = 0;
    int result, maxNum = 0;
    
    for (int i = 0; i <= limit; i++) {
        for (int j = -999; j < 1000; j++) {
            int n = 0;
            result = n * (n + j) + primes[i];
            if (result < 2) {
                continue;
            }
            while (result == primes[locateGreatestPrime(result, primes)]) {
                n++;
                result = n * (n + j) + primes[i];
                if (result < 2) {
                    break;
                }
            }
            if (n > maxNum) {
                maxNum = n;
                product = primes[i] * j;
            }
        }
    }
    
    for (int i = 0; i <= limit; i++) {
        for (int j = -999; j < 1000; j++) {
            int n = 0;
            result = n * (n + j) - primes[i];
            if (result < 2) {
                continue;
            }
            while (result == primes[locateGreatestPrime(result, primes)]) {
                n++;
                result = n * (n + j) - primes[i];
                if (result < 2) {
                    break;
                }
            }
            if (n > maxNum) {
                maxNum = n;
                product = primes[i] * j;
            }
        }
    }
    
    cout << product << "\n";
}

int locateGreatestPrime(int a, int primes[])
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