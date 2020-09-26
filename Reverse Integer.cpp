/*
Problem Description : (LC 7)
------------------------------------------------------------------------------------------
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 
32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your 
function returns 0 when the reversed integer overflows.
*/
//Code:
//---------------------------------------------------------------------------------------------
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int negative = (x<0)?-1:1;
        while(x){
            int rem = x%10;
            cout<<rem<<"\n";
            res = res*10+rem;
            x = x/10;
            if(res>INT_MAX || res<INT_MIN)
                return 0;
        }
        return res;
    }
};