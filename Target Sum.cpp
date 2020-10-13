/*
Problem Description : (LC 494)
-------------------------------------------------------------------------------------
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer,
 you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 

Constraints:

The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
//Code:
//-----------------------------------------------------------------------------------------------
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int size = nums.size();
        int sum = 0;
        int zeroCount = 0;
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            if (nums[i] == 0)
                zeroCount++;
        }

        int targetSum = S + (sum - S) / 2;
        if (S > sum || (S + sum) % 2 != 0)
            return 0;
        int dp[size + 1][targetSum + 1];
        for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= targetSum; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (nums[i - 1] == 0 || nums[i - 1] > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
            }
        }
        return pow(2, zeroCount) * dp[size][targetSum];
    }
};

/*
Approach : 
Given : arr we need to find subset sum equal to target sum by placing + or - before the elements and add the subset elements.
Return  : return such subset counts where we can find sum of the subset elemets with above contrains.
Process :
Say, given array is [1,2,1,3] and target sum is 1.
the subsets are : 
[+1,+2,+1,-3]
[-1,-2,+1, +3]
[+1,-2,-1,+3]
if we look closely, we just need to find two subsets where the diff is given sum.
[+1,+2,+1,-3] = (1,2, 1) -(3)
 -1,-2,+1, +3] = (1,3) - (1,2)
[+1,-2,-1,+3] = (1,3) - (1,2)

so, from the above intuition we can say that:
subset1 - subset2 = S ...................(eq.1)
subset1 + subset2 = arraySum ...............(eq.2) (obviously)
now, doing (eq1 + eq2):
2*(subset1 + subset2) = S+arraySum;
subset1 = (S+arraySum)/2;

SO, now we have reduced this problem to another easier variant problem which is, find subset count whose sum is 
eqalt to subset1.

Now few changes in the code due to some test cases : 
1. line 47 for the test case : integer overflow
[2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53]
S : 2147483647

2. line 43 for the test case : 
[0,0,0,0,0,0,0,0,1]
S : 1
O/P : 256

3. line 65 for the test case : 
[1,0]
S : 1


THANKS TO : https://www.youtube.com/channel/UC5WO7o71wvxMxEtLRkPhiQQ FOR HIS AMAZING DP SERIES