/*
Problem Description : (LC 476)
----------------------------------------------------------------------------------------
Given a positive integer num, output its complement number. The complement strategy is to 
flip the bits of its binary representation.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
num >= 1
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

*/
//Code:
//----------------------------------------------------------------------------------------------
class Solution {
public:
    int bitwiseComplement(int N) {
       if(N == 0)
           return 1;
        int i = 31;
        while((N>>i & 1) == 0)// get the most significant set bit
            i--;
        int res = 0;
        for(;i>=0 ; i--){
            res = res<<1; // making a space add new value
            res = res | ((N>>i)&1?0:1);
        }
        return res;
    }
};