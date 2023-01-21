#include <bits/stdc++.h>

#ifndef _OPERATIONS_H
#define _OPERATIONS_H

using namespace std;

typedef struct
{
    int numerator;
    int denom;
} number;

// Fungsi cek apakah bilangan bisa dibagi
bool isDivisible(int x, int y)
{
    return (y != 0);
}

number operation(char opr, number num1, number num2)
{
    number ans;
    if (opr == '+' || opr == '-'){
        if (num1.denom != num2.denom){
            int lcm = (num1.denom * num2.denom) / __gcd(num1.denom,num2.denom);
            num1.numerator = num1.numerator * lcm / num1.denom;
            num2.numerator = num2.numerator * lcm / num2.denom;
            num1.denom = num2.denom = lcm;
        } else {
            if (opr == '+'){
                ans.numerator = num1.numerator + num2.numerator;
            }
            else {
                ans.numerator = num1.numerator - num2.numerator;
            }
        }
        ans.denom = num1.denom;
    }

    else if (opr == '*'){
        ans.numerator = num1.numerator * num2.numerator;
        ans.denom = num1.denom * num2.denom;
    }
    else if (opr == '/'){
        ans.numerator = num1.numerator * num2.denom;
        ans.denom = num1.denom * num2.numerator;
    }
    return ans;
}

#endif