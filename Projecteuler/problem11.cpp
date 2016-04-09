//
//  problem11.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem11.hpp"

#include <iostream>
#include <fstream>

void run_problem11()
{
    using namespace std;
    int arr[20][20];
    ifstream fin("problem11.txt");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++){
            fin >> arr[i][j];
        }
    }
    fin.close();
    
    int maxProduct = 0, p;
    //vertical
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j + 3 < 20; j++) {
            p = arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3];
            maxProduct = ((p > maxProduct) ? p : maxProduct);
        }
    }
    //horizontal
    for (int i = 0; i + 3 < 20; i++) {
        for (int j = 0; j < 20; j++) {
            p = arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j];
            maxProduct = ((p > maxProduct) ? p : maxProduct);
        }
    }
    //diagonal1
    for (int i = 0; i + 3 < 20; i++) {
        for (int j = 0; j + 3 < 20; j++) {
            p = arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3];
            maxProduct = ((p > maxProduct) ? p : maxProduct);
        }
    }
    //diagonal2
    for (int i = 3; i < 20; i++) {
        for (int j = 0; j + 3 < 20; j++) {
            p = arr[i][j]*arr[i-1][j+1]*arr[i-2][j+2]*arr[i-3][j+3];
            maxProduct = ((p > maxProduct) ? p : maxProduct);
        }
    }
    std::cout << maxProduct << "\n";
    
}