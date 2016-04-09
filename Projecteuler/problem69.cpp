//
//  problem69.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem69.hpp"

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

static int locateGreatestPrime(int a, int primes[]);
static int eulerPhi(int n, int primes[]);

void run_problem69()
{
    clock_t start = clock();
    
    using namespace std;
    int *primes = (int *)malloc(100008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 100008; i++) {
        fin >> primes[i];
    }
    fin.close();
    double ratio, maxRatio = 0;
    int maxIdx = 1;
    for (int i = 4; i <= 1000000; i++) {
        ratio = i / double(eulerPhi(i, primes));
        //        cout << "i = " << i << " ratio = " << ratio << " phi = " << eulerPhi(i, primes) << "\n";
        if (ratio > maxRatio) {
            maxRatio = ratio;
            maxIdx = i;
        }
    }
    cout << "Number with max ratio: " << maxIdx << "\nRatio: " << maxRatio << "\n";
    cout << "Time consumed: " << double(clock() - start)/CLOCKS_PER_SEC << "s\n";
}

static int eulerPhi(int n, int primes[])
{
    int primeFactors[10];
    for (int i = 0; i < 10; i++) {
        primeFactors[i] = 0;
    }
    
    int IDX = locateGreatestPrime(n/2, primes);
    int numPrimeFactors = 0;
    for (int i = 0; i <= IDX; i++) {
        if (n % primes[i] == 0) {
            primeFactors[numPrimeFactors++] = primes[i];
        }
    }
    
    int phi = n;
    if (numPrimeFactors == 0) {
        return n-1;
    }
    for (int i = 0; i < numPrimeFactors; i++) {
        phi = (phi/primeFactors[i]) * (primeFactors[i]-1);
    }
    return phi;
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
