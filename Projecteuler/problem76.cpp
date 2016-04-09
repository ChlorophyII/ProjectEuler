//
//  problem76.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem76.hpp"

#include <iostream>

static int waysWithUB(int a, int ub);

void run_problem76()
{
    using namespace std;
    cout << waysWithUB(100, 99) << "\n";
}

static int waysWithUB(int a, int ub)
{
    if (a < 2) {
        return 1;
    }
    
    int residue;
    int cnt = 0;
    for (int i = (a < ub) ? a:ub; i > 0; i--) {
        residue = a - i;
        cnt += waysWithUB(residue, i);
    }
    return cnt;
}