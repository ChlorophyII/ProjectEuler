//
//  problem81.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem81.hpp"

#include <ctime>
#include <iostream>
#include <fstream>

void run_problem81()
{
    using namespace std;
    clock_t start = clock();
    int mat[80][80];
    char x;
    ifstream fin("problem 81.txt");
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 79; j++) {
            fin >> mat[i][j];
            fin >> x;
        }
        fin >> mat[i][79];
    }
    fin.close();
    for (int i = 1; i < 80; i++) {
        mat[0][i] += mat[0][i-1];
        mat[i][0] += mat[i-1][0];
    }
    for (int i = 1; i < 80; i++) {
        for (int j = 1; j < 80; j++) {
            mat[i][j] += (mat[i-1][j] < mat[i][j-1]) ? mat[i-1][j] : mat[i][j-1];
        }
    }
    cout << mat[79][79] << "\n";
    cout << double(clock()-start)/CLOCKS_PER_SEC << "s\n";
}
