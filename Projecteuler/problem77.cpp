//
//  problem77.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem77.hpp"

#include <iostream>
#include <fstream>
#include <cmath>

static int locateGreatestPrime(int a, int primes[]);

static int waysWithUB(int a, int ub, int primes[]);

void run_problem77()
{
    using namespace std;
    int *primes = (int *)malloc(100008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 100008; i++) {
        fin >> primes[i];
    }
    fin.close();
    
    int i = 1;
    while (waysWithUB(i, i, primes) < 5000) {
        i++;
    }
    cout << i << "\n";
    //    for (int i = 0; i < 100; i++) {
    //        std::cout << i << " " << waysWithUB(i, i, primes) << "\n";
    //    }
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

static int waysWithUB(int a, int ub, int primes[])
{
    if (a == 0) {
        return 1;
    }
    else if (a == 1){
        return 0;
    }
    
    int cnt = 0;
    int residue;
    for (int pos = locateGreatestPrime((a < ub) ? a:ub, primes); pos > -1; pos--)
    {
        residue = a - primes[pos];
        cnt += waysWithUB(residue, primes[pos], primes);
    }
    return cnt;
}