//
//  BIGNUM.hpp
//  Projecteuler
//
//  Created by Shi Yue on 2/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#ifndef BIGNUM_hpp
#define BIGNUM_hpp

#include <stdio.h>

#endif /* BIGNUM_hpp */

const int __BIGNUMLENGTH = 500;

class BIGNUM
{
public:
    BIGNUM();
    void add(long long a);
    void add(BIGNUM a);
    void mult(long long a);
    void mult(BIGNUM a);
    void pow(int a);
    int getDigit(int digit);
    int getNumDigits();
    int getDigitSum();
    void disp();
private:
    char ch[__BIGNUMLENGTH];
    int numDigits;
    void oneDigitMult(int a);
    void shift(int digit);
    char getDigitChar(int digit);
};