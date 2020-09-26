/*
Problem Description : (LC 29)
---------------------------------------------------------------------------------
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part.
 For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit 
signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function
 returns 231 − 1 when the division result overflows.
 */
//Code: https://www.youtube.com/watch?v=bdxJHWIyyqI&ab_channel=ScalerAcademy
//-------------------------------------------------------------------------------------------------------
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long x = abs(dividend);
        long long y = abs(divisor);
        long long quotient = 0;
        long long temp = 0;
        int sign  = (dividend<0) ^ (divisor<0)?-1:1;
        for(int i = 31 ; i>= 0 ; i--){
            if(temp + (y<<i)<=x){
                temp = temp + (y<<i);
                quotient = quotient | (1LL<<i);
            }
        }
        if(sign<0)
            quotient = -quotient;
        return quotient<INT_MIN || quotient>INT_MAX?INT_MAX:quotient;
        
    }
  
    
};