//
//  BIGNUM.cpp
//  Projecteuler
//
//  Created by Shi Yue on 2/4/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

#include <assert.h>
#include <iostream>
#include "BIGNUM.hpp"

BIGNUM::BIGNUM()
{
    for (int i = 0; i < __BIGNUMLENGTH; i++) {
        ch[i] = '0';
    }
    numDigits = 0;
}

void BIGNUM::add(long long a)
{
    long long aa = a;
    int length = 0;
    while(aa > 0)
    {
        length++;
        aa /= 10;
    }
    int d1, d2;
    bool carry = false;
    for (int i = 0; i < length; i++)
    {
        d1 = ch[i] - '0';
        d2 = a % 10;
        a /= 10;
        ch[i] = (d1 + d2 + carry) % 10 + '0';
        carry = (d1 + d2 + carry) / 10;
    }
    ch[length] += carry;
    numDigits = (numDigits > length) ? numDigits:length;
    numDigits += ch[numDigits] != '0';
}

void BIGNUM::add(BIGNUM a)
{
    bool carry = false;
    int d1, d2;
    for (int i = 0; i < a.getNumDigits(); i++)
    {
        d1 = ch[i] - '0';
        d2 = a.getDigit(i);
        ch[i] = (d1 + d2 + carry) % 10 + '0';
        carry = (d1 + d2 + carry) / 10;
    }
    ch[a.getNumDigits()] += carry;
    numDigits = (numDigits > a.getNumDigits()) ? numDigits:a.getNumDigits();
    numDigits += ch[numDigits] != '0';
}

void BIGNUM::oneDigitMult(int a)
{
    assert(a < 10);
    if (a == 0) {
        BIGNUM b;
        *this = b;
        return;
    }
    int d, carry = 0;
    for (int i = 0; i < numDigits; i++)
    {
        d = ch[i] - '0';
        ch[i] = (d * a + carry) % 10 + '0';
        carry = (d * a + carry) / 10;
    }
    ch[numDigits] += carry;
    numDigits += ch[numDigits] != '0';
}

void BIGNUM::shift(int digit)
{
    if (digit == 0) {
        return;
    }
    for (int i = numDigits + digit - 1; i > digit - 1; i--)
    {
        ch[i] = ch[i-digit];
    }
    for (int i = 0; i < digit; i++)
    {
        ch[i] = '0';
    }
    numDigits += digit;
}

void BIGNUM::mult(long long a)
{
    long long aa = a;
    int length = 0;
    while(aa > 0)
    {
        length++;
        aa /= 10;
    }
    BIGNUM *arr = new BIGNUM[length];
    for (int i = 0; i < length; i++)
    {
        arr[i] = *this;
    }
    for (int i = 0; i < length; i++)
    {
        arr[i].oneDigitMult(a % 10);
        arr[i].shift(i);
        a /= 10;
    }
    for (int i = 1; i < length; i++)
    {
        arr[0].add(arr[i]);
    }
    *this = arr[0];
    delete [] arr;
}

void BIGNUM::mult(BIGNUM a)
{
    int aDigits = a.getNumDigits();
    BIGNUM *arr = new BIGNUM[aDigits];
    for (int i = 0; i < aDigits; i++) {
        arr[i] = *this;
    }
    for (int i = 0; i < aDigits; i++)
    {
        arr[i].oneDigitMult(a.getDigit(i));
        arr[i].shift(i);
    }
    for (int i = 1; i < aDigits; i++)
    {
        arr[0].add(arr[i]);
    }
    *this = arr[0];
    delete [] arr;
}

void BIGNUM::pow(int a)
{
    BIGNUM b = *this;
    for (int i = 1; i < a; i++) {
        this->mult(b);
    }
}

int BIGNUM::getDigit(int digit)
{
    return int(ch[digit] - '0');
}

int BIGNUM::getDigitSum()
{
    int sum = 0;
    for (int i = 0; i < numDigits; i++) {
        sum += getDigit(i);
    }
    return sum;
}

int BIGNUM::getNumDigits()
{
    return numDigits;
}

char BIGNUM::getDigitChar(int digit)
{
    return ch[digit];
}

void BIGNUM::disp()
{
    for (int i = numDigits-1; i > -1; i--)
    {
        std::cout << ch[i];
    }
}