/*
Problem Description : (LC 69)
--------------------------------------------------------------------------
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/
//Code:
//------------------------------------------------------------------------------
class Solution
{
public:
    int sqrtUtil(int val)
    {
        int start = 1, end = val;
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid == val / mid)
            {
                return mid;
            }
            if (mid > val / mid)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;
        return sqrtUtil(x);
    }
};