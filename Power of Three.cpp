/*
Problem Description : (LC 326)
---------------------------------------------------------------------------------------
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?
*/
//Code:
--------------------------------------------------------------------------------------------
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        return pow(3,(int)(log2(n)/log2(3))) == n;
    }
};
/*
3^p = n;
log(3^p) = log(n);
p(log 3) = log n;
p = log n/ log 3;