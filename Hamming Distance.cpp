/*
Problem Description : (LC 461)
---------------------------------------------------------------------------------
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

*/

Code;
-----------------------------------------------------------------------------------------------
class Solution {
public:
    int countSetBits(int val){
        if(val == 0)
            return 0;
        return (val & 1) + countSetBits(val>>1);
    }
    int hammingDistance(int x, int y) {
        int xorOfXandY = x ^ y;
        return countSetBits(xorOfXandY);
    }
};
TC : (-)(logn) (Theta of logn), where n is no of bits
