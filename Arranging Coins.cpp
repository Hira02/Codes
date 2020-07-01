/*
Problem Description : (LC 441)
---------------------------------------------------------------
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

*/

Code:
--------------------------------------------------------------------
//Binary search approach
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0;
        int right = n;
        long mid, curr;
        while(left<=right){
            mid = left + (right - left)/2;
            curr = mid*(mid+1)/2;
            if(curr == n)
                return (int)mid;
            else if(curr<n){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return (int)right;
    }
};
// iterative solution
class Solution {
public:
    int arrangeCoins(int n) {
        int level = 1;
        long starEachStair = 0;
        while(1){
            
            starEachStair += level;
            if(starEachStair==n)
                return level;
            else if(starEachStair>n)
                return level-1;
            level++;
            
        }
        return level;
    }
};
