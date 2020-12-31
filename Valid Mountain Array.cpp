/*
Problem Description : (LC 941)
------------------------------------------------------------------------------------
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < A[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104
*/
//Code:
//---------------------------------------------------------------------------------------------------
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        int start = 0;
        int end = arr.size()-1;
        while(start!= end-1 && arr[start]<arr[start+1])
            start++;
        while(end!= start  && arr[end-1]>arr[end])
            end--;
        return start == end && end!= arr.size()-1 && start != 0;
        
    }
};