//
//  problem123.cpp
//  Projecteuler
//
//  Created by Shi Yue on 29/10/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem123.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

static int locateGreatestPrime(int a, int primes[]);

void run_problem123(){
    using namespace std;
    int *primes = (int *)malloc(10008 * sizeof(int));
    ifstream fin("/Users/SY/Documents/C++/Projecteuler/Projecteuler/primes.txt");
    for (int i = 0; i < 10008; i++) {
        fin >> primes[i];
    }
    fin.close();

    for (int i = 0;; i++){
        long product = long(2) * long(i + 1) * long(primes[i]);
        cout << i << "         " << product << "\n";
        if (product > 10000000000){
            cout << i+1 << "\n";
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
