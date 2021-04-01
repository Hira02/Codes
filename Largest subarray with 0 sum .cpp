/*
Problem Description : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/?company[]=Microsoft&company[]=Microsoft&problemStatus=unsolved&problemType=functional&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&page=1&sortBy=submissions&query=company[]MicrosoftproblemStatusunsolvedproblemTypefunctionaldifficulty[]-2difficulty[]-1difficulty[]0page1sortBysubmissionscompany[]Microsoft#
------------------------------------------------------------------------------------------------------------------------------------------------------
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the
largest subarray with 0 sum.

Expected Time Complexity: O(N*Log(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 104
-1000 <= A[i] <= 1000, for each valid i
*/
//Code:
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int, int> Map;
    int maxLen = 0;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum+= A[i];
        if(A[i] == 0 && maxLen == 0)
            maxLen = 1;
        if(sum == 0)
            maxLen = i+1;
        if(Map.find(sum) != Map.end()){
            maxLen = max(maxLen, i-Map[sum]);
        }else
            Map[sum] = i;
    }
    return maxLen;
}
