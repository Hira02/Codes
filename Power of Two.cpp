/*
Problem Description: (LC 231)
--------------------------------------------------
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/

Code:1 TC : O(logn)
---------------------------------------------------------------
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        if(n == 1)
            return true;
        return n%2 == 0 && isPowerOfTwo(n/2);
    }
};
Code: 2 TC : O(1)
    -----------------------------------------------------------
    class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (!(n&(n-1)));
    }
};
/*
All power of two numbers have only one bit set. So count the no. of set bits and if you get 1 then number is a power of 2. 
*/
