//
//  problem14.cpp
//  Projecteuler
//
//  Created by Shi Yue on 9/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include "problem14.hpp"

/*
 This problem is solved by brute force, and the code is written in matlab.
 The function seqLength is simply written in recursive form, which may cause over flow or exceed recursion limit.
 The answer is 837799, and the sequence length is 524.
 */

//This is a solution provided by others.
//Link: https://projecteuler.net/quote_post=6-h9f6vJ6Vo2d8HzAz
#include <stdio.h>

void run_problem14()
{
    int longest = 0;
    int terms = 0;
    int i;
    unsigned long j;
    
    for (i = 1; i <= 1000000; i++)
    {
        j = i;
        int this_terms = 1;
        
        while (j != 1)
        {
            this_terms++;
            
            if (this_terms > terms)
            {
                terms = this_terms;
                longest = i;
            }
            
            if (j % 2 == 0)
            {
                j = j / 2;
            }
            else
            {
                j = 3 * j + 1;
            }
        }
    }
    
    printf("longest: %d (%d)\n", longest, terms);
}