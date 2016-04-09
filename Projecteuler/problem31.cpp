//
//  problem31.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem31.hpp"

#include <iostream>

static int locate(int denomination);

void run_problem31()
{
    int denomination[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    int arr[200];
    for (int i = 0; i < 200; i++) {
        arr[i] = 0;
    }
    int cnt = 1;
    arr[0] = 200;
    while (arr[0] != 1) {
        int j, residue = 0;
        for ( j = 199; j > -1; j--) {
            if (arr[j] == 1) {
                arr[j] = 0;
                residue++;
            }
            else if (arr[j] > 1)
                break;
        }
        
        residue += arr[j] - denomination[locate(arr[j]) - 1];
        arr[j] = denomination[locate(arr[j]) - 1];
        int ub = arr[j];
        while (residue > 0) {
            if (residue >= ub) {
                arr[++j] = ub;
                residue -= ub;
            }
            else {
                ub = denomination[locate(ub)-1];
            }
        }
        cnt++;
    }
    std::cout << cnt << "\n";
    
}

static int locate(int denomination)
{
    switch (denomination) {
        case 200:
            return 7;
        case 100:
            return 6;
        case 50:
            return 5;
        case 20:
            return 4;
        case 10:
            return 3;
        case 5:
            return 2;
        case 2:
            return 1;
        case 1:
            return 0;
        default:
            return -1;
    }
}