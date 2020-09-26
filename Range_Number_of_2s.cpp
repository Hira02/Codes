/*
Problem Description : 
---------------------------------------------------------------------------------------
Count the number of 2s as digit in all numbers from 0 to n.

Code:
--------------------------------------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
long long int numberOf2sinRange(long long int number)
{
    int count = 1;
    long long int tens = 1;
    long long int ott = 0;
    long long int sum = 0;
    long long int sNum = number;

    while (sNum)
    {
        int rem = sNum % 10;
        if (rem < 2)
        {
            sum = sum + rem * ott;
        }
        else if (rem == 2)
        {
             sum = sum + rem * ott;
            sum = sum + 2 + 1;
           
        }
        else

        {
            sum = sum + rem * ott;
            sum = sum + tens;
            
        }
        ott = (count)*tens;
        tens = tens * 10;
        count++;
        sNum = sNum / 10;
    }

    return sum;
}
int main()
{
    int n = 100;
    cout << numberOf2sinRange(n);
    return 0;
}
