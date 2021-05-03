/*
Problem Description : (LC 658)
---------------------------------------------------------------------------------------------------------------------------
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

*/
//Code:
//---------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int high = arr.size()-k;
        // vector<int> temp(len);
        int low =0;
        while(low<high){
            int mid = low + (high - low)/2;
            if(x - arr[mid]>arr[mid+k]-x){
                low = mid+1;
            }else
                high = mid;
        }
        return vector<int>(arr.begin()+low, arr.begin()+low+k);
        
    }
};

/*
Explanations: 

lest say window is arr[mid] to arr[mid+k]
now:
if x - arr[mid]<arr[mid+k]-x  move left

---------------x----arr[mid]-------------arr[mid+k]-----------------

if x - arr[mid]<arr[mid+k]-x move right

-----------arr[mid]-----x-----------------arr[mid+k]----------------

if  x-arr[mid]<arr[mid+k]-x  move window right

----------------arr[mid]-------------------x-------arr[mid+k]-------


if  x-arr[mid]>arr[mid+k]-x  move window left

-----------------arr[mid]-----------------arr[mid+k]--------x-------




so basically our target is to put x as middle as possible


Time O(log(N - K)) to binary research and find result
Space O(K) to create the returned list.

Mention: https://leetcode.com/vincent_gui/
*/
