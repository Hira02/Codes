/*
Problem Description : (LC 264)
----------------------------------------------------------
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

Code:
-------------------------------------------------------------------------------------
class Solution {
public:
    
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        int ugly[n+1];
        ugly[0]=1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        int next_ugly_2 = 2;
        int next_ugly_3 = 3;
        int next_ugly_5 = 5;
        int next_ugly = 1;
        for(int i = 1; i < n ; i++){//3
             next_ugly = min(next_ugly_2,min(next_ugly_3, next_ugly_5));//4,6,5
            cout<<next_ugly<<" ";
            ugly[i] = next_ugly; // 4
            if(next_ugly == next_ugly_2){ 
                i2 = i2 + 1;
                next_ugly_2 = ugly[i2]*2;
            } if(next_ugly == next_ugly_3){
                i3 = i3+1;
                next_ugly_3 = ugly[i3]*3;
            }if(next_ugly == next_ugly_5){
                i5 = i5 + 1;
                next_ugly_5 = ugly[i5]*5;
            }
        }
        return ugly[n-1];
    }
};
