//
//  problem243.hpp
//  Projecteuler
//
//  Created by Shi Yue on 10/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#ifndef problem243_hpp
#define problem243_hpp

#include <stdio.h>

#endif /* problem243_hpp */

//=========================== Problem 243 ===========================
//Title: Resilience
/*
 Start date: 4/8/2016
 Finish date: 4/8/2016
 
 Description:
 A positive fraction whose numerator is less than its denominator is called a proper fraction.
 For any denominator, d, there will be d−1 proper fractions; for example, with d = 12:
 1/12 , 2/12 , 3/12 , 4/12 , 5/12 , 6/12 , 7/12 , 8/12 , 9/12 , 10/12 , 11/12 .
 
 We shall call a fraction that cannot be cancelled down a resilient fraction.
 Furthermore we shall define the resilience of a denominator, R(d), to be the ratio of its proper fractions that are resilient; for example, R(12) = 4/11 .
 In fact, d = 12 is the smallest denominator having a resilience R(d) < 4/10 .
 
 Find the smallest denominator d, having a resilience R(d) < 15499/94744 .
 */

//It is said that this problem is based on problem 69.
//This problem really makes me annoyed, for the code is revised for two times.
//Euler Phi function is used, and it seems to be the only way to success.

void run_problem243();