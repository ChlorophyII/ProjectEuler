//
//  problem16.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem16.hpp"

#include <iostream>

void run_problem16()
{
    char arr[331];
    for (int i = 0; i < 331; i++) {
        arr[i] = '0';
    }
    arr[0] = '1';
    bool addOne = false;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 330; j++) {
            if (addOne) {
                addOne = (arr[j]-'0')*2/10;
                arr[j] = (arr[j]-'0')*2%10+'1';
            }
            else
            {
                addOne = (arr[j]-'0')*2/10;
                arr[j] = (arr[j]-'0')*2%10+'0';
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 331; i++) {
        sum += arr[i]-'0';
    }
    std::cout << sum << "\n";
}