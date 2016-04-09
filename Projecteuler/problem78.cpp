//
//  problem78.cpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem78.hpp"
#include <ctime>
#include <iostream>
const int LIMIT = 30001;

static int waysLookUp(int *ways, int n, int ub);
static int locate(int n, int ub);
static int waysWithUB(int *ways, int a, int ub);

void run_problem78()
{
    clock_t start = clock();
    using namespace std;
    int *ways = new int [(LIMIT * LIMIT + 1) >> 1];
    for (int i = 0; i < (LIMIT * LIMIT + 1) >> 1; i++) {
        ways[i] = 0;
    }
    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 1;
    
    int i, w = 1;
    for (i = 10000; i < 30001; i++) {
        w = waysWithUB(ways, i, i);
        cout << i << " " << w << "\n";
        if (w == 0) {
            cout << "THANK GOD!!! IT'S DONE!!!\n";
            break;
        }
        
    }
    cout << "Time consumed: " << double(clock()-start)/CLOCKS_PER_SEC << "s\n";
}

static int waysLookUp(int *ways, int n, int ub)
{
    return ways[locate(n, ub)];
}

static int locate(int n, int ub)
{
    if (ub >= n) {
        return ((n+1)*(n+2) >> 1) - 1;
    }
    else
        return (n*(n+1) >> 1) + ub;
}

static int waysWithUB(int *ways, int a, int ub)
{
    if (waysLookUp(ways, a, ub))
        return waysLookUp(ways, a, ub);
    else
    {
        int residue;
        int cnt = 0;
        for (int i = (a < ub) ? a:ub; i > 0; i--) {
            residue = a - i;
            cnt = (cnt + waysWithUB(ways, residue, i))%1000000;
        }
        ways[locate(a, ub)] = cnt;
        return cnt;
    }
}
