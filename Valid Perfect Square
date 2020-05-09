Problem Description:
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

Code:
---------------------------
class Solution {
public:
    bool isPerfectSquare(int num) {
            if (num < 0) return false;
            if (num == 0) return true;

            long left = 1;
            long right = INT_MAX;

            while (left <= right)
            {
                long mid = (left + right) / 2;
                long midSqr = mid * mid;
                if (midSqr == num) return true;
                else if (midSqr > num) right = mid - 1;
                else left = mid + 1;
            }

            return false;
    }
};
