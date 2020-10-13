/*
Problem Description : (LC 9)
-----------------------------------------------------------------------------
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Follow up: Could you solve it without converting the integer to a string?

 

Example 1:

Input: x = 121
Output: true
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Example 4:

Input: x = -101
Output: false
 

Constraints:

-231 <= x <= 231 - 1
*/
//Code:
//--------------------------------------------------------------------------------------------------
class Solution {
public:
    int reverseHalf(int val){ // reverse half of the number
        int reverseNum = 0;
        while(val>reverseNum){
            reverseNum = reverseNum*10 + val%10;
            val = val/10;
        }
        return reverseNum;
    }
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int reverseNum = reverseHalf(x);
         // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == reverseNum || x == reverseNum/10/* if x is odd*/;
    }
};
//TC : O(log10^n)