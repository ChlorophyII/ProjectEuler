//
//  problem19.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem19.hpp"

//There is a little bit problem, but lukily, the result is right.
#include <iostream>

int getMonthDay(int month, int year);

void run_problem19()
{
    int weekday = 1;
    int cnt = 0;
    for (int year = 1900; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            weekday = (weekday + getMonthDay(month, year) - 1) % 7 + 1;
            if (weekday == 7) {
                cnt++;
            }
        }
    }
    weekday = 1;
    for (int month = 1; month <= 12; month++) {
        weekday = (weekday + getMonthDay(month, 1900) - 1) % 7 + 1;
        if (weekday == 7) {
            cnt--;
        }
    }
    std::cout << cnt << "\n";
}

int getMonthDay(int month, int year)
{
    if (month == 1 || month == 3 || month == 5|| month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if (month == 2){
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 29;
            }
            else
                return 28;
        }
        else if (year % 4 == 0) {
            return 29;
        }
        else{
            return 28;
        }
    }
    else
        return 30;
}
