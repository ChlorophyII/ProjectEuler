//
//  problem29.cpp
//  Projecteuler
//
//  Created by Shi Yue on 15/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem29.hpp"
#include <iostream>

void run_problem29()
{
    int totalNum = 99 * 99;
    bool sieveFor2[600];
    bool sieveFor3[400];
    bool sieveFor567[200];
    
    for (int i = 0; i < 600; i++) {
        sieveFor2[i] = false;
    }
    for (int i = 0; i < 400; i++) {
        sieveFor3[i] = false;
    }
    for (int i = 0; i < 200; i++) {
        sieveFor567[i] = false;
    }
    
    for (int i = 2; i < 100; i++) {
        sieveFor2[i] = true;
        sieveFor3[i] = true;
        sieveFor567[i] = true;
    }
    for (int i = 4; i < 200; i += 2) {
        sieveFor2[i] = true;
        sieveFor3[i] = true;
        sieveFor567[i] = true;
    }
    for (int i = 6; i < 300; i += 3) {
        sieveFor2[i] = true;
        sieveFor3[i] = true;
    }
    for (int i = 8; i < 400; i += 4) {
        sieveFor2[i] = true;
        sieveFor3[i] = true;
    }
    for (int i = 10; i < 500; i += 5) {
        sieveFor2[i] = true;
    }
    for (int i = 12; i < 600; i += 6) {
        sieveFor2[i] = true;
    }
    
    int cnt = 0;
    for (int i = 0; i < 600; i++) {
        if (sieveFor2[i]) {
            cnt++;
        }
    }
    totalNum -= 6 * 99 - cnt;
    
    cnt = 0;
    for (int i = 0; i < 400; i++) {
        if (sieveFor3[i]) {
            cnt++;
        }
    }
    totalNum -= 4 * 99 - cnt;
    
    cnt = 0;
    for (int i = 0; i < 200; i++) {
        if (sieveFor567[i]) {
            cnt++;
        }
    }
    totalNum -= 3 * (2 * 99 - cnt);
    
    std::cout << totalNum << "\n";
}