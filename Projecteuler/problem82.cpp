//
//  problem82.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem82.hpp"

#include <ctime>
#include <iostream>
#include <fstream>

static void go(int mat[80][80], int col);

void run_problem82()
{
    using namespace std;
    clock_t start = clock();
    int mat[80][80];
    char x;
    ifstream fin("problem 82.txt");
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 79; j++) {
            fin >> mat[i][j];
            fin >> x;
        }
        fin >> mat[i][79];
    }
    fin.close();
    for (int i = 1; i < 80; i++) {
        go(mat, i);
    }
    int min = mat[0][79];
    for (int i = 1; i < 80; i++) {
        min = (min < mat[i][79]) ? min : mat[i][79];
    }
    cout << min << "\n";
    cout << double(clock()-start)/CLOCKS_PER_SEC << "s\n";
}

static void go(int mat[80][80], int col)
{
    int temp[80];
    for (int i = 0; i < 80; i++) {
        int s[80];
        int sum;
        for (int j = i; j > -1; j--) {
            sum = 0;
            for (int k = i; k >= j; k--) {
                sum += mat[k][col];
            }
            s[j] = sum + mat[j][col-1];
        }
        for (int j = i; j < 80; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += mat[k][col];
            }
            s[j] = sum + mat[j][col-1];
        }
        temp[i] = s[0];
        for (int j = 1; j < 80; j++) {
            temp[i] = (temp[i] < s[j]) ? temp[i] : s[j];
        }
    }
    for (int i = 0; i < 80; i++) {
        mat[i][col] = temp[i];
    }
}