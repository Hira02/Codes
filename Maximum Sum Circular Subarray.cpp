Problem Description:(LC 918)
---------------------------------
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array. 
(Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
Also, a subarray may only include each element of the fixed buffer A at most once.  
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1


Solution Approach:
--------------------------------------------------
Here we will be using Kadane's algo with some trick,

@geeksforGeeks Approach(https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/)
There can be two cases for the maximum sum:
Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there. 
Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there.
Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping. 
Let us see how. Wrapping of contributing elements implies non wrapping of non contributing elements,
so find out the sum of non contributing elements and subtract this sum from the total sum.
To find out the sum of non contributing, invert sign of each element and then run Kadane’s algorithm.
Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum continuous positive in 
the inverted arrays.

Finally we compare the sum obtained by both cases, and return the maximum of the two sums.


Code:
--------------------------------------------------------------------------------------------
class Solution {
public:
    int findMaxSumUsingKadane(vector<int>&A){
        int max_sum_here = 0;
        int max_sum = 0;
        for(int  i = 0 ; i  <A.size() ; i++){
            max_sum_here+=A[i];
            if(max_sum_here<0)
                max_sum_here = 0;
            max_sum = max(max_sum, max_sum_here);
        }
        return max_sum;
    }
    int findMaxSum(vector<int> &A){
        int kadaneSum = findMaxSumUsingKadane(A);
        int wrap_sum = 0;
        for(int  i = 0 ; i < A.size() ; i ++){
            wrap_sum+=A[i];
            A[i] = -A[i];
        }
        wrap_sum = wrap_sum  + findMaxSumUsingKadane(A);
        return max(wrap_sum, kadaneSum);
    }
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 1)
            return A[0];
        int singleMax = INT_MIN;
        //when all the elements are negative
        for(int  i = 0 ; i < A.size() ; i ++){
            if(A[i]>singleMax){
                singleMax = A[i];
            }
        }
        if(singleMax<0)
            return singleMax;
        //when the elements are mix of -ve and +ve
        return findMaxSum(A);
        // return max(singleMax, maxSum);
//         
    }
};

TC: O(n)
SC : O(1)


