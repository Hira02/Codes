/*
Problem Description : (LC 581)
------------------------------------------------------------------------------
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order,
 then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
*/
//Code:
//------------------------------------------------------------------------------------------

#1:
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> minStore(nums.size());
        vector<int> maxStore(nums.size());
        int start = 0, end = nums.size() - 1;
        int currMin = INT_MAX;
        int currMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            maxStore[i] = currMax = max(currMax, nums[i]);
        for (int i = nums.size() - 1; i >= 0; i--)
            minStore[i] = currMin = min(currMin, nums[i]);
        while (start <= end && nums[start] <= minStore[start])
        {
            start++;
            // cout<<minStore[start]<<" ";
        }

        while (start <= end && nums[end] >= maxStore[end])
            end--;
        return end - start + 1;
    }
};


#2:
class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        int s = 0, e = n-1, i, max, min;  
        
  
// step 1(a) of above algo 
for (s = 0; s < n-1; s++) 
{ 
    if (arr[s] > arr[s+1]) 
    break; 
} 
if (s == n-1) 
{ 
    // cout << "The complete array is sorted"; 
    return 0; 
} 
  
// step 1(b) of above algo 
for(e = n - 1; e > 0; e--) 
{ 
    if(arr[e] < arr[e-1]) 
    break; 
} 
  
// step 2(a) of above algo 
max = arr[s]; min = arr[s]; 
for(i = s + 1; i <= e; i++) 
{ 
    if(arr[i] > max) 
    max = arr[i]; 
    if(arr[i] < min) 
    min = arr[i]; 
} 
  
// step 2(b) of above algo 
for( i = 0; i < s; i++) 
{ 
    if(arr[i] > min) 
    {  
    s = i; 
    break; 
    }      
}  
  
// step 2(c) of above algo 
for( i = n -1; i >= e+1; i--) 
{ 
    if(arr[i] < max) 
    { 
    e = i; 
    break; 
    }  
}  
      
// step 3 of above algo 

return e-s+1; 
    }
};

//https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
