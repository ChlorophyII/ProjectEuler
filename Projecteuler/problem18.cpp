
//
//  problem18.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem18.hpp"

#include <iostream>
#include <fstream>
#include <cmath>

void run_problem18()
{
    using namespace std;
    int *a, cnt = 0, size = 100;
    a = (int *)malloc(100 * sizeof(int));
    
    ifstream fin("problem 18.txt");
    while (!fin.eof()) {
        fin >> a[cnt++];
        if (cnt == size) {
            a = (int *)realloc(a, (100 + size)*sizeof(int));
            size += 100;
        }
    }
    int row = (sqrt(1+8*cnt)-1)/2;
    for (int r = row; r > 1; r--) {
        int st = r*(r-1)/2;
        for (int c = 0; c < r-1; c++) {
            a[st+c-r+1] += (a[st+c] > a[st+c+1]) ? (a[st+c]):(a[st+c+1]);
        }
    }
    std::cout << a[0] << "\n";
}