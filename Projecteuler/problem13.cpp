//
//  problem13.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem13.hpp"

#include <iostream>
#include <fstream>
#include <math.h>

void run_problem13()
{
    using namespace std;
    ifstream fin("problem13.txt");
    string str[100];
    for (int i = 0; i < 100; i++) {
        fin >> str[i];
    }
    fin.close();
    int sum[12];
    for (int i = 0; i < 12; i++) {
        sum[i] = 0;
        for (int j = 0; j < 100; j++) {
            sum[i] += str[j].at(i)-'0';
        }
    }
    
    long long totalSum = 0;
    for (int i = 0; i < 12; i++) {
        totalSum += sum[11-i] * pow(10,i);
    }
    
    for (int i = 1; i < 20; i++) {
        if (int(totalSum / pow(10, i)) == 0) {
            totalSum /= pow(10, i - 10);
            break;
        }
    }
    
    std::cout << totalSum << "\n";
}