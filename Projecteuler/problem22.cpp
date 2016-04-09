//
//  problem22.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem22.hpp"

#include <iostream>
#include <fstream>
#include <string>

static int letterScore(char ch);

static int strScore(std::string str);

static void quickSort(std::string *array, int n);

static int partition(std::string *array, int n);

void run_problem22()
{
    using namespace std;
    ifstream fin("problem 22.txt");
    string names[5163];//There are 5163 names;
    int i = 0;
    char ch;
    while (!fin.eof()) {
        fin >> ch;
        if ( ch == ',') {
            i++;
        }
        else if (ch != '"') {
            names[i] = names[i] + ch;
        }
    }
    i++;
    
    quickSort(names, i);
    long total = 0;
    for (int j = 0; j < i; j++) {
        total += (j+1) * strScore(names[j]);
    }
    cout << total << "\n";
}

static int letterScore(char ch)
{
    return ch - 'A' + 1;
}

static int strScore(std::string str)
{
    int score = 0;
    for (int i = 0; i < str.length(); i++) {
        score += letterScore(str.at(i));
    }
    return score;
}

static int partition(std::string *array, int n)
{
    int lh = 1, rh;
    std::string pivot, temp;
    pivot = array[0];
    rh = n-1;
    do {
        while (lh < rh && array[rh] >= pivot) {
            rh--;
        }
        while (lh < rh && array[lh] <= pivot) {
            lh++;
        }
        if (lh != rh) {
            temp = array[lh];
            array[lh] = array[rh];
            array[rh] = temp;
        }
    } while (lh != rh);
    if (array[lh] >= pivot) {
        return 0;
    }
    array[0] = array[lh];
    array[lh] = pivot;
    return lh;
}

static void quickSort(std::string *array, int n)
{
    int p;
    if (n > 1) {
        p = partition(array, n);
        quickSort(array, p);
        quickSort(array + p + 1, n - p - 1);
    }
}