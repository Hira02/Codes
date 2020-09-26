/*
Problem Description  : (LC 04) HARD
--------------------------------------------------------------------------------------
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
//Code:
//----------------------------------------------------------------------------------------------------
class Solution {
public:
    /*
    median in any sorted array is the point where elements on the left are smaller 
    and on right are higher than median value
    so our intution is to divide both the array in two equal parts so that
    left part will have all the lower value than the right part
    then we can find median based on normal procedure
    Source  :https://www.youtube.com/watch?v=LPFhl65R7ww&t=1013s&ab_channel=TusharRoy-CodingMadeSimple
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //nums1 has to be lower or equal
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        //our targeris to partition first nums1, and then based on that we will partition nums2
        int start = 0;
        int end = len1;
        while(start<= end){
            int partitionX = (start+end)/2;
            int partitionY = (len1+len2+1)/2 - partitionX; // +1 to work for odd and even lenght
            //partitionX+partitionY = (len1+len2+1)/2 as to make left side and right side with same length(+-1)
            int maxX = (partitionX == 0)?INT_MIN:nums1[partitionX-1];
            int maxY = (partitionY == 0)?INT_MIN:nums2[partitionY-1];
            int minX = (partitionX == len1)?INT_MAX:nums1[partitionX];
            int minY = (partitionY == len2)?INT_MAX:nums2[partitionY];
            if(maxX<=minY && maxY<=minX){
                if((len1+len2)%2 == 0){
                  return (double) (max(maxX, maxY) + min(minX, minY))/2;
                }else{
                    return (double)max(maxX, maxY);
                }
            }else if(maxX>minY){
                end = partitionX-1;
            }else if(maxY>minX){
                start = partitionX+1;
            }
        }
        return -1;
    }
};