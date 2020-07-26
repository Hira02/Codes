/*
Problem Description : (LC 258)
---------------------------------------------------------------------------------------------
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

Code:
--------------------------------------------------------------------------------------------------------
class Solution {
public:
    int addDigits(int num) {
        if(num != 0 && num%9 == 0)
            return 9;
       return (num>=10)?num%9:num; 
    }
};
//TC : O(1)
