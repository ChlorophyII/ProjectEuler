//
//  main.cpp
//  Projecteuler
//
//  Created by Shi Yue on 24/3/2016.
//  Copyright © 2016 Shi Yue. All rights reserved.
//

/*
 Catalogue:
 --ID--|--------------------Title--------------------|-----Answer-----|--Finish Date--
   2   | Even Fibonacci numbers                      | 4613732        |  3/24/2016
   3   | Larest Prime Factor                         | 6857           |  3/24/2016
   4   | Largest palindrome product                  | 906609         |  3/24/2016
   5   | Smallest multiple                           | 232792560      |  3/24/2016
   6   | Sum square difference                       | 25164150       |  3/24/2016
   7   | 10001st prime                               | 104743         |  3/24/2016
   8   | Largest product in a series                 | 23514624000    |  3/24/2016
   9   | Special Pythagorean triplet                 | 31875000       |  3/24/2016
   10  | Summation of primes                         | 142913828922   |  3/25/2016
   11  | Largest product in a grid                   | 70600674       |  3/26/2016
   12  | Highly divisible triangular number          | 76576500       |  3/26/2016
   13  | Large sum                                   | 55373762303860 |  3/26/2016
   14  | Longest Collatz sequence                    | 837799         |  3/29/2016
   16  | Power digit sum                             | 1366           |  3/26/2016
   17
   18
 
 
 */

#include "problem16.hpp"

int main()
{
    run_problem16();
}





//=========================== Problem 18 ===========================
//Title: Maximum path sum I
/*
 Start date: 3/25/2016
 Finish date: 3/26/2016
 
 Description:
 By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 
 3
 7 4
 2 4 6
 8 5 9 3
 
 That is, 3 + 7 + 4 + 9 = 23.
 
 Find the maximum total from top to bottom of the triangle below:
 
 75
 95 64
 17 47 82
 18 35 87 10
 20 04 82 47 65
 19 01 23 75 03 34
 88 02 77 73 07 63 67
 99 65 04 28 06 16 70 92
 41 41 26 56 83 40 80 70 33
 41 48 72 33 47 32 37 16 94 29
 53 71 44 65 25 43 91 52 97 51 14
 70 11 33 28 77 73 17 78 39 68 17 57
 91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 
 NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 */
//Solution:
/*
#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
    using namespace std;
    int *a, cnt = 0, size = 100;
    a = (int *)malloc(100 * sizeof(int));
    
    ifstream fin("problem 18.txt");
    while (!fin.eof()) {
        fin >> a[cnt++];
        if (cnt == size) {
            a = (int *)realloc(a, (100 + size)*sizeof(int));
            size += 100;
        }
    }
    int row = (sqrt(1+8*cnt)-1)/2;
    for (int r = row; r > 1; r--) {
        int st = r*(r-1)/2;
        for (int c = 0; c < r-1; c++) {
            a[st+c-r+1] += (a[st+c] > a[st+c+1]) ? (a[st+c]):(a[st+c+1]);
        }
    }
    std::cout << a[0];
}
*/

//=========================== Problem 19 ===========================
//Title: Counting Sundays
/*
 Start date: 3/25/2016
 Finish date: 4/4/2016
 
 Description:
 You are given the following information, but you may prefer to do some research for yourself.
 
 1 Jan 1900 was a Monday.
 Thirty days has September,
 April, June and November.
 All the rest have thirty-one,
 Saving February alone,
 Which has twenty-eight, rain or shine.
 And on leap years, twenty-nine.
 A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */
//Solution:
/*
 //There is a little bit problem, but lukily, the result is right.
#include <iostream>

int getMonthDay(int month, int year);

int main()
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
    std::cout << cnt;
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
*/

//=========================== Problem 20 ===========================
//Title: Factorial digit sum
/*
 Start date: 3/29/2016
 Finish date: 4/3/2016
 
 Description:
 n! means n × (n − 1) × ... × 3 × 2 × 1
 
 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 
 Find the sum of the digits in the number 100!
 */
//Solution:
/*
#include <iostream>
#include "BIGNUM.hpp"
//Set __BIGNUMLENGTH = 200

int main()
{
    BIGNUM a;
    a.add(1);
    for (int i = 1; i < 101; i++) {
        a.mult(i);
//        a.disp();
//        std::cout << "\n" << i << "\n\n";
    }
    int sum = 0;
    a.disp();
    for (int i = 0; i < a.getNumDigits(); i++) {
        sum += a.getDigit(i);
    }
    std::cout << "\n" << sum << "\n";
}
*/

//=========================== Problem 21 ===========================
//Title: Amicable numbers
/*
 Start date: 4/4/2016
 Finish date: 4/4/2016
 
 Description:
 Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 
 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 
 Evaluate the sum of all the amicable numbers under 10000.
 */
//Solution:
/*
//There is some small problem, but luckily, the result is correct.
#include <iostream>

int sumOfProperDivisors(int a);

int main()
{
    int sum = 0;
    int sumOfPD[10001];
    bool isAmicableNum[10001];
    sumOfPD[0] = -1;
    for (int i = 1; i < 10001; i++) {
        sumOfPD[i] = sumOfProperDivisors(i);
    }
    for (int i = 1; i < 10001; i++) {
        if (sumOfPD[i] > 10000 || sumOfPD[i] == i) {
            continue;
        }
        if (sumOfPD[i] < 10000 && sumOfPD[sumOfPD[i]] == i) {
            isAmicableNum[i] = true;
        }
        else {
            isAmicableNum[i] = false;
        }
    }
    for (int i = 1; i < 10001; i++) {
        if (isAmicableNum[i]) {
            sum += i;
        }
    }
    std::cout << sum;
}

int sumOfProperDivisors(int a)
{
    int sum = 0;
    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            sum += i;
        }
    }
    return sum;
}
*/

//=========================== Problem 22 ===========================
//Title: Names scores
/*
 Start date: 4/4/2016
 Finish date: 4/7/2016
 
 Description:
 Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 
 What is the total of all the name scores in the file?
 */
//Solution:
/*
#include <iostream>
#include <fstream>
#include <string>

int letterScore(char ch)
{
    return ch - 'A' + 1;
}

int strScore(std::string str)
{
    int score = 0;
    for (int i = 0; i < str.length(); i++) {
        score += letterScore(str.at(i));
    }
    return score;
}

void quickSort(std::string *array, int n);

int partition(std::string *array, int n);

int main()
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
    cout << total << " haha";
}

int partition(std::string *array, int n)
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

void quickSort(std::string *array, int n)
{
    int p;
    if (n > 1) {
        p = partition(array, n);
        quickSort(array, p);
        quickSort(array + p + 1, n - p - 1);
    }
}
*/

//=========================== Problem 23 ===========================
//Title: Non-abundant sums
/*
 Start date: 4/7/2016
 Finish date: 4/7/2016
 
 Description:
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */
//Solution:
/*
#include <iostream>

bool isAbundant(int a);
bool isSumOfAbdNumbers(int a, bool *isAbd);

int main()
{
    bool isAbd[28123];
    for (int i = 1; i < 28123; i++) {
        isAbd[i] = isAbundant(i);
    }
    long sum = 0;
    for (int i = 1; i < 28123; i++) {
        if (!isSumOfAbdNumbers(i, isAbd)) {
            sum += i;
        }
    }
    std::cout << sum;
}

bool isAbundant(int a)
{
    int sum = 0;
    for (int i = 1; i <= a/2; i++) {
        if (a % i == 0) {
            sum += i;
        }
    }
    if (sum > a)
        return true;
    else
        return false;
}

bool isSumOfAbdNumbers(int a, bool *isAbd)
{
    for (int i = 1; i <= a/2 ; i++) {
        if (isAbd[i] && isAbd[a-i]) {
            return true;
        }
    }
    return false;
}
*/

//=========================== Problem 25 ===========================
//Title: 1000-digit Fibonacci number
/*
 Start date: 3/29/2016
 Finish date: 3/29/2016
 
 Description:
 The Fibonacci sequence is defined by the recurrence relation:
 
 Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 Hence the first 12 terms will be:
 
 F1 = 1
 F2 = 1
 F3 = 2
 F4 = 3
 F5 = 5
 F6 = 8
 F7 = 13
 F8 = 21
 F9 = 34
 F10 = 55
 F11 = 89
 F12 = 144
 The 12th term, F12, is the first term to contain three digits.
 
 What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 */
//Solution:
/*
#include <iostream>
#include <cmath>

const long double Phi = (1+sqrt(5))/2, phi = (1-sqrt(5))/2;
const long double sqrt5 = sqrt(5);
int main()
{
    int i = 1;
    for (;logl((powl(Phi,i)-pow(phi,i))/sqrt5)/logl(10.0) < 999 ; i++) {
    }
    std::cout << (powl(Phi,i)-pow(phi,i))/sqrt5;
    std::cout << i;
}
*/

//=========================== Problem 26 ===========================
//Title: Reciprocal cycles
/*
 Start date: 4/8/2016
 Finish date: 4/8/2016
 
 Description:
 A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 
 1/2	= 	0.5
 1/3	= 	0.(3)
 1/4	= 	0.25
 1/5	= 	0.2
 1/6	= 	0.1(6)
 1/7	= 	0.(142857)
 1/8	= 	0.125
 1/9	= 	0.(1)
 1/10	= 	0.1
 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 
 Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */
//Solution:
/*
#include <iostream>

int reciprocalCycleLength(int a);

int main()
{
    int d = 0, length = 0;
    for (int i = 1; i < 1000; i++) {
        if (reciprocalCycleLength(i) > length) {
            length = reciprocalCycleLength(i);
            d = i;
        }
    }
    std::cout << "d = " << d << "\nlength = " << length << "\n";
}

int reciprocalCycleLength(int a)
{
    int dividend = 1;
    for (int i = 0; i < 50; i++) {
        while (dividend < a) {
            dividend *= 10;
        }
        int j;
        for (j = 0; dividend - (j+1) * a >= 0; j++) {
        }
        dividend -= j * a;
        if (dividend == 0) {
            return 0;
        }
    }
    int r = dividend;
    int cnt = 0;
    while (cnt == 0 || r != dividend) {
        if (dividend < a) {
            dividend *= 10;
        }
        while (dividend < a) {
            dividend *= 10;
            cnt++;
        }
        int j;
        for (j = 0; dividend - (j+1) * a >= 0; j++) {
        }
        dividend -= j * a;
        cnt++;
    }
    return cnt;
}
*/

//=========================== Problem 28 ===========================
//Title: Number spiral diagonals
/*
 Start date: 4/8/2016
 Finish date:
 
 Description:
 Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 
 21 22 23 24 25
 20  7  8  9 10
 19  6  1  2 11
 18  5  4  3 12
 17 16 15 14 13
 
 It can be verified that the sum of the numbers on the diagonals is 101.
 
 What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 */
//Solution:
/*
#include <iostream>

int main()
{
    long a = 1, sum = 1;
    for (int i = 2; i <= 1000; i += 2) {
        a += i;
        sum += a;
        a += i;
        sum += a;
        a += i;
        sum += a;
        a += i;
        sum += a;
    }
    std::cout << sum;
}
*/

//=========================== Problem 29 ===========================
//Title: Quadratic primes
/*
 Start date: 4/9/2016
 Finish date: 4/9/2016
 
 Description:
 Euler discovered the remarkable quadratic formula:
 
 n^2 + n + 41
 
 It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
 
 The incredible formula  n^2 − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
 
 Considering quadratics of the form:
 
 n² + an + b, where |a| < 1000 and |b| < 1000
 
 where |n| is the modulus/absolute value of n
 e.g. |11| = 11 and |−4| = 4
 Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 */
//Solution:
/*
#include <iostream>
#include <fstream>
#include <cmath>

int locateGreatestPrime(int a, int primes[]);

int main()
{
    using namespace std;
    int *primes = (int *)malloc(100008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 100008; i++) {
        fin >> primes[i];
    }
    fin.close();
    
    int limit = locateGreatestPrime(1000, primes);
    
    int product = 0;
    int result, maxNum = 0;
    
    for (int i = 0; i <= limit; i++) {
        for (int j = -999; j < 1000; j++) {
            int n = 0;
            result = n * (n + j) + primes[i];
            if (result < 2) {
                continue;
            }
            while (result == primes[locateGreatestPrime(result, primes)]) {
                n++;
                result = n * (n + j) + primes[i];
                if (result < 2) {
                    break;
                }
            }
            if (n > maxNum) {
                maxNum = n;
                product = primes[i] * j;
            }
        }
    }
    
    for (int i = 0; i <= limit; i++) {
        for (int j = -999; j < 1000; j++) {
            int n = 0;
            result = n * (n + j) - primes[i];
            if (result < 2) {
                continue;
            }
            while (result == primes[locateGreatestPrime(result, primes)]) {
                n++;
                result = n * (n + j) - primes[i];
                if (result < 2) {
                    break;
                }
            }
            if (n > maxNum) {
                maxNum = n;
                product = primes[i] * j;
            }
        }
    }
    
    cout << product;
}

int locateGreatestPrime(int a, int primes[])
{
    //return i, where primes[i] <= a;
    int i = a / log(a);
    while (primes[i] < a) {
        i++;
    }
    while (primes[i] > a) {
        i--;
    }
    return i;
}
*/

//=========================== Problem 30 ===========================
//Title: Digit fifth powers
/*
 Start date: 4/8/2016
 Finish date: 4/8/2016
 
 Description:
 Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 
 1634 = 1^4 + 6^4 + 3^4 + 4^4
 8208 = 8^4 + 2^4 + 0^4 + 8^4
 9474 = 9^4 + 4^4 + 7^4 + 4^4
 As 1 = 1^4 is not a sum it is not included.
 
 The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 
 Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */
//Solution:
/*
#include <iostream>
#include <cmath>

int main()
{
    int a, b, c, d, e, f;
    double m;
    long sum = 0;
    for (int i = 2; i < 1000000; i++) {
        a = i % 10;
        b = (i / 10) % 10;
        c = (i / 100) % 10;
        d = (i / 1000) % 10;
        e = (i / 10000) % 10;
        f = (i / 100000) % 10;
        m = pow(a, 5) + pow(b, 5) + pow(c, 5) + pow(d, 5) + pow(e, 5) + pow(f, 5);
        if (m < i + 0.5 && m > i - 0.5) {
            sum += i;
            std::cout << i << "\n";
        }
    }
    std::cout << sum;
}
*/

//=========================== Problem 31 ===========================
//Title: Coin sums
/*
 Start date: 4/8/2016
 Finish date: 4/8/2016
 
 Description:
 In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 
 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 It is possible to make £2 in the following way:
 
 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 How many different ways can £2 be made using any number of coins?
 */
//Solution:
/*
#include <iostream>

int locate(int denomination);

int main()
{
    int denomination[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    int arr[200];
    for (int i = 0; i < 200; i++) {
        arr[i] = 0;
    }
    int cnt = 1;
    arr[0] = 200;
    while (arr[0] != 1) {
        int j, residue = 0;
        for ( j = 199; j > -1; j--) {
            if (arr[j] == 1) {
                arr[j] = 0;
                residue++;
            }
            else if (arr[j] > 1)
                break;
        }
        
        residue += arr[j] - denomination[locate(arr[j]) - 1];
        arr[j] = denomination[locate(arr[j]) - 1];
        int ub = arr[j];
        while (residue > 0) {
            if (residue >= ub) {
                arr[++j] = ub;
                residue -= ub;
            }
            else {
                ub = denomination[locate(ub)-1];
            }
        }
        cnt++;
    }
    std::cout << cnt;
    
}

int locate(int denomination)
{
    switch (denomination) {
        case 200:
            return 7;
        case 100:
            return 6;
        case 50:
            return 5;
        case 20:
            return 4;
        case 10:
            return 3;
        case 5:
            return 2;
        case 2:
            return 1;
        case 1:
            return 0;
        default:
            return -1;
    }
}
*/

//=========================== Problem 34 ===========================
//Title: Digit factorials
/*
 Start date: 4/3/2016
 Finish date: 4/3/2016
 
 Description:
 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 
 Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 
 Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */
//Solution:
/*
#include <iostream>

//Note, 9! * 7 = 2540160, which means 2540160 is the upper bound of such numbers.

int oneDigitFactorial(int a);

int main()
{
    long sum = 0;
    int a, b;
    for (int i = 3; i < 2540160; i++)
    {
        a = i;
        b = 0;
        while (a > 0) {
            b += oneDigitFactorial(a % 10);
            a /= 10;
        }
        if (i == b)
            sum += i;
    }
    std::cout << sum;
}

int oneDigitFactorial(int a)
{
    switch (a) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 24;
        case 5:
            return 120;
        case 6:
            return 720;
        case 7:
            return 5040;
        case 8:
            return 40320;
        case 9:
            return 362880;
        default:
            break;
    }
    return 0;
}
*/

//=========================== Problem 56 ===========================
//Title: Powerful digit sum
/*
 Start date: 4/3/2016
 Finish date: 4/3/2016
 
 Description:
 A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
 
 Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
 */
//Solution:
/*
#include <iostream>
#include "BIGNUM.hpp"
//Set __BIGNUMLENGTH = 200

int main()
{
    int maxDigitalSum = 0;
    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
            BIGNUM bn;
            bn.add(a);
            bn.pow(b);
            maxDigitalSum = (maxDigitalSum > bn.getDigitSum()) ? maxDigitalSum:bn.getDigitSum();
        }
    }
    std::cout << maxDigitalSum;
}
*/

//=========================== Problem 63 ===========================
//Title: Powerful digit counts
/*
 Start date: 4/3/2016
 Finish date: 4/3/2016
 
 Description:
 The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
 
 How many n-digit positive integers exist which are also an nth power?
 */
//Solution:
/*
#include <iostream>
#include <cmath>

int main()
{
    //Note that even using long long, it will overflow.
//    int cnt = 0;
//     lb, ub, p;
//    for (int i = 0; i < 25; i++) {
//        for (int j = 1; j < 10; j++) {
//            lb = pow(10, i-1) - 1;
//            ub = pow(10, i);
//            p = pow(j, i);
////            std::cout << lb << " " << ub << " " << p << "\n";
//            if (lb < p && p < ub)
//            {
//                std::cout << j << " " << i << " " << ++cnt << " " << p << "\n";
//            }
//        }
//    }
//    for (int i = 1; i < 10; i++) {
//        for (int j = -1; j > -10; j--) {
//            ub = -(pow(10, i-1) - 1);
//            lb = -pow(10, i);
//            p = pow(j, i);
//            if (lb < p && p < ub)
//            {
//                std::cout << j << " " << i << " " << ++cnt << " " << p << "\n";
//            }
//        }
//    }
    int cnt = 0;
    for (int i = 1; i < 25; i++) {
        cnt += 10 - ceil(pow(10, 1 - 1.0/i));
    }
    std::cout << cnt;
}
*/
 
//=========================== Problem # ===========================
//Title:
/*
 Start date:
 Finish date:
 
 Description:
 
 */
//Solution:

//=========================== Problem 67 ===========================
//Title: Maximum path sum II
/*
 Start date: 3/26/2016
 Finish date: 3/26/2016
 
 Description:
 By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 
 3
 7 4
 2 4 6
 8 5 9 3
 
 That is, 3 + 7 + 4 + 9 = 23.
 
 Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
 
    https://projecteuler.net/project/resources/p067_triangle.txt
 
 NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 2^99 altogether! If you could check one trillion (10^12) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
 */
//Solution:
/*
#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
    using namespace std;
    int *a, cnt = 0, size = 100;
    a = (int *)malloc(100 * sizeof(int));
    
    ifstream fin("problem 67.txt");
    while (!fin.eof()) {
        fin >> a[cnt++];
        if (cnt == size) {
            a = (int *)realloc(a, (100 + size)*sizeof(int));
            size += 100;
        }
    }
    int row = (sqrt(1+8*cnt)-1)/2;
    for (int r = row; r > 1; r--) {
        int st = r*(r-1)/2;
        for (int c = 0; c < r-1; c++) {
            a[st+c-r+1] += (a[st+c] > a[st+c+1]) ? (a[st+c]):(a[st+c+1]);
        }
    }
    std::cout << a[0];
}
*/

//=========================== Problem 69 ===========================
//Title: Totient maximum
/*
 Start date: 4/8/2016
 Finish date: 4/8/2016
 
 Description:
 Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
 
 n	Relatively Prime	φ(n)	n/φ(n)
 2	1                   1       2
 3	1,2                 2       1.5
 4	1,3                 2       2
 5	1,2,3,4             4       1.25
 6	1,5                 2       3
 7	1,2,3,4,5,6         6       1.1666...
 8	1,3,5,7             4       2
 9	1,2,4,5,7,8         6       1.5
 10	1,3,7,9             4       2.5
 It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.
 
 Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
 */
//Solution:
/*
 //Problem 243 is a much harder version of this problem.
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

int locateGreatestPrime(int a, int primes[]);
int eulerPhi(int n, int primes[]);


int main()
{
    clock_t start = clock();
    
    using namespace std;
    int *primes = (int *)malloc(100008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 100008; i++) {
        fin >> primes[i];
    }
    fin.close();
    double ratio, maxRatio = 0;
    int maxIdx = 1;
    for (int i = 4; i <= 1000000; i++) {
        ratio = i / double(eulerPhi(i, primes));
//        cout << "i = " << i << " ratio = " << ratio << " phi = " << eulerPhi(i, primes) << "\n";
        if (ratio > maxRatio) {
            maxRatio = ratio;
            maxIdx = i;
        }
    }
    cout << "Number with max ratio: " << maxIdx << "\nRatio: " << maxRatio << "\n";
    cout << "Time consumed: " << double(clock() - start)/CLOCKS_PER_SEC << "s\n";
}

int eulerPhi(int n, int primes[])
{
    int primeFactors[10];
    for (int i = 0; i < 10; i++) {
        primeFactors[i] = 0;
    }
    
    int IDX = locateGreatestPrime(n/2, primes);
    int numPrimeFactors = 0;
    for (int i = 0; i <= IDX; i++) {
        if (n % primes[i] == 0) {
            primeFactors[numPrimeFactors++] = primes[i];
        }
    }
    
    int phi = n;
    if (numPrimeFactors == 0) {
        return n-1;
    }
    for (int i = 0; i < numPrimeFactors; i++) {
        phi = (phi/primeFactors[i]) * (primeFactors[i]-1);
    }
    return phi;
}

int locateGreatestPrime(int a, int primes[])
{
    //return i, where primes[i] <= a;
    int i = a / log(a);
    while (primes[i] < a) {
        i++;
    }
    while (primes[i] > a) {
        i--;
    }
    return i;
}
*/

//=========================== Problem 76 ===========================
//Title: Counting summations
/*
 Start date: 4/3/2016
 Finish date: 4/3/2016
 
 Description:
 It is possible to write five as a sum in exactly six different ways:
 
 4 + 1
 3 + 2
 3 + 1 + 1
 2 + 2 + 1
 2 + 1 + 1 + 1
 1 + 1 + 1 + 1 + 1
 
 How many different ways can one hundred be written as a sum of at least two positive integers?
 */
//Solution:
/*
#include <iostream>

int waysWithUB(int a, int ub);

int main()
{
    using namespace std;
    cout << waysWithUB(100, 99);
}

int waysWithUB(int a, int ub)
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
*/

//=========================== Problem 77 ===========================
//Title: Prime summations
/*
 Start date: 4/3/2016
 Finish date: 4/3/2016
 
 Description:
 It is possible to write ten as the sum of primes in exactly five different ways:
 
 7 + 3
 5 + 5
 5 + 3 + 2
 3 + 3 + 2 + 2
 2 + 2 + 2 + 2 + 2
 
 What is the first value which can be written as the sum of primes in over five thousand different ways?
 */
//Solution:
/*
#include <iostream>
#include <fstream>
#include <cmath>

int locateGreatestPrime(int a, int primes[]);

int waysWithUB(int a, int ub, int primes[]);

int main()
{
    using namespace std;
    int *primes = (int *)malloc(100008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 100008; i++) {
        fin >> primes[i];
    }
    fin.close();
    
    int i = 1;
    while (waysWithUB(i, i, primes) < 5000000) {
        i++;
    }
    cout << i;
//    for (int i = 0; i < 100; i++) {
//        std::cout << i << " " << waysWithUB(i, i, primes) << "\n";
//    }
}

int locateGreatestPrime(int a, int primes[])
{
    //return i, where primes[i] <= a;
    int i = a / log(a);
    while (primes[i] < a) {
        i++;
    }
    while (primes[i] > a) {
        i--;
    }
    return i;
}

int waysWithUB(int a, int ub, int primes[])
{
    if (a == 0) {
        return 1;
    }
    else if (a == 1){
        return 0;
    }
    
    int cnt = 0;
    int residue;
    for (int pos = locateGreatestPrime((a < ub) ? a:ub, primes); pos > -1; pos--)
    {
        residue = a - primes[pos];
        cnt += waysWithUB(residue, primes[pos], primes);
    }
    return cnt;
}
*/

//=========================== Problem 78 ===========================
//Title: Coin partitions
/*
 Start date: 4/4/2016
 Finish date:
 
 Description:
 Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.
 
 OOOOO
 OOOO   O
 OOO   OO
 OOO   O   O
 OO   OO   O
 OO   O   O   O
 O   O   O   O   O
 Find the least value of n for which p(n) is divisible by one million.
 */
//Solution:
//#include <ctime>
//#include <iostream>
//const int LIMIT = 30001;
//
//int numPartitions(int n);
//int waysLookUp(int *ways, int n, int ub);
//int locate(int n, int ub);
//int waysWithUB(int *ways, int a, int ub);
//
//int main()
//{
//    clock_t start = clock();
//    using namespace std;
//    int *ways = new int [(LIMIT * LIMIT + 1) >> 1];
//    for (int i = 0; i < (LIMIT * LIMIT + 1) >> 1; i++) {
//        ways[i] = 0;
//    }
//    ways[0] = 1;
//    ways[1] = 1;
//    ways[2] = 1;
//    
//    int i, w = 1;
//    for (i = 10000; i < 30001; i++) {
//        w = waysWithUB(ways, i, i);
//        cout << i << " " << w << "\n";
//        if (w == 0) {
//            cout << "THANK GOD!!! IT'S DONE!!!\n";
//            break;
//        }
//        
//    }
//    cout << "Time consumed: " << double(clock()-start)/CLOCKS_PER_SEC << "s\n";
//}
//
//int waysLookUp(int *ways, int n, int ub)
//{
//    return ways[locate(n, ub)];
//}
//
//int locate(int n, int ub)
//{
//    if (ub >= n) {
//        return ((n+1)*(n+2) >> 1) - 1;
//    }
//    else
//        return (n*(n+1) >> 1) + ub;
//}
//
//int waysWithUB(int *ways, int a, int ub)
//{
//    if (waysLookUp(ways, a, ub))
//        return waysLookUp(ways, a, ub);
//    else
//    {
//        int residue;
//        int cnt = 0;
//        for (int i = (a < ub) ? a:ub; i > 0; i--) {
//            residue = a - i;
//            cnt = (cnt + waysWithUB(ways, residue, i))%1000000;
//        }
//        ways[locate(a, ub)] = cnt;
//        return cnt;
//    }
//}

//=========================== Problem 81 ===========================
//Title: Path sum: two ways
/*
 Start date: 4/4/2016
 Finish date: 4/4/2016
 
 Description:
 https://projecteuler.net/problem=81
 */
//Solution:
/*
#include <ctime>
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;
    clock_t start = clock();
    int mat[80][80];
    char x;
    ifstream fin("problem 81.txt");
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 79; j++) {
            fin >> mat[i][j];
            fin >> x;
        }
        fin >> mat[i][79];
    }
    fin.close();
    for (int i = 1; i < 80; i++) {
        mat[0][i] += mat[0][i-1];
        mat[i][0] += mat[i-1][0];
    }
    for (int i = 1; i < 80; i++) {
        for (int j = 1; j < 80; j++) {
            mat[i][j] += (mat[i-1][j] < mat[i][j-1]) ? mat[i-1][j] : mat[i][j-1];
        }
    }
    cout << mat[79][79] << "\n";
    cout << double(clock()-start)/CLOCKS_PER_SEC << "s\n";
}
*/

//=========================== Problem 82 ===========================
//Title: Path sum: three ways
/*
 Start date: 4/4/2016
 Finish date: 4/4/2016
 
 Description:
 https://projecteuler.net/problem=82
 */
//Solution:
/*
#include <ctime>
#include <iostream>
#include <fstream>

void go(int mat[80][80], int col);

int main()
{
    using namespace std;
    clock_t start = clock();
    int mat[80][80];
    char x;
    ifstream fin("problem 82.txt");
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 79; j++) {
            fin >> mat[i][j];
            fin >> x;
        }
        fin >> mat[i][79];
    }
    fin.close();
    for (int i = 1; i < 80; i++) {
        go(mat, i);
    }
    int min = mat[0][79];
    for (int i = 1; i < 80; i++) {
        min = (min < mat[i][79]) ? min : mat[i][79];
    }
    cout << min << "\n";
    cout << double(clock()-start)/CLOCKS_PER_SEC << "s\n";
}

void go(int mat[80][80], int col)
{
    int temp[80];
    for (int i = 0; i < 80; i++) {
        int s[80];
        int sum;
        for (int j = i; j > -1; j--) {
            sum = 0;
            for (int k = i; k >= j; k--) {
                sum += mat[k][col];
            }
            s[j] = sum + mat[j][col-1];
        }
        for (int j = i; j < 80; j++) {
            sum = 0;
            for (int k = i; k <= j; k++) {
                sum += mat[k][col];
            }
            s[j] = sum + mat[j][col-1];
        }
        temp[i] = s[0];
        for (int j = 1; j < 80; j++) {
            temp[i] = (temp[i] < s[j]) ? temp[i] : s[j];
        }
    }
    for (int i = 0; i < 80; i++) {
        mat[i][col] = temp[i];
    }
}
*/

//=========================== Problem 206 ===========================
//Title: Concealed Square
/*
 Start date: 4/4/2016
 Finish date: 4/4/2016
 
 Description:
 Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
 where each “_” is a single digit.
 */
//Solution:
/*
#include <iostream>

int main()
{
    long long sq, i;
    
    for (i = 1010101010; i < 1389026623; i++) {
        sq = i*i;
        if (sq % 10 == 0) {
            sq /= 100;
            if (sq % 10 == 9) {
                sq /= 100;
                if (sq % 10 == 8) {
                    sq /= 100;
                    if (sq % 10 == 7) {
                        sq /= 100;
                        if (sq % 10 == 6) {
                            sq /= 100;
                            if (sq % 10 == 5) {
                                sq /= 100;
                                if (sq % 10 == 4) {
                                    sq /= 100;
                                    if (sq % 10 == 3) {
                                        sq /= 100;
                                        if (sq % 10 == 2) {
                                            std::cout << i;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
*/
 
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
//Solution:
/*
 //It is said that this problem is based on problem 69.
 //This problem really makes me annoyed, for the code is revised for two times.
 //Euler Phi function is used, and it seems to be the only way to success.
 
#include <iostream>
#include <fstream>
#include <cmath>

int locateGreatestPrime(int a, int primes[])
{
    //return i, where primes[i] <= a;
    int i = a / log(a);
    while (primes[i] < a) {
        i++;
    }
    while (primes[i] > a) {
        i--;
    }
    return i;
}

int main()
{
    using namespace std;
    
    int *primes = (int *)malloc(10008 * sizeof(int));
    ifstream fin("primes.txt");
    for (int i = 0; i < 1000000; i++) {
        fin >> primes[i];
    }
    fin.close();
    
    double bound = 15499.0/94744.0;
    
    int i;
    double a, b;
    for (i = 3;;i++)
    {
        a = 1.0, b = 1.0;
        for (int j = 0; j < i; j++) {
            a *= (primes[j] - 1.0);
            b *= primes[j];
        }
        cout  << a/(b - 1.0) << "\n";
        if (a/(b - 1.0) < bound) {
            cout  << i << " " << a/(b - 1.0) << "\n";
            break;
        }
    }
    i--;
    a /= primes[i] - 1;
    b /= primes[i];
    
    for (int i = 4; i < primes[i]; i++) {
        if (locateGreatestPrime(i, primes) == i) {
            continue;
        }
        if ((a * i)/(b * i - 1.0) < bound) {
            long result = long(b * i);
            cout << "i = " << i << "\nThe final result is: " << result << "\n";
            break;
        }
    }
}
*/

//=========================== Problem # ===========================
//Title:
/*
 Start date:
 Finish date:
 
 Description:
 
 */
//Solution:
