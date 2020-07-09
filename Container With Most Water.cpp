/*
Problem Description : (LC 11)
---------------------------------------------------------------------------
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line
i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
Code:
---------------------------------------------------------------------------------------------
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left_pointer = 0;
        int right_pointer = height.size()-1;
        while(left_pointer<right_pointer){
            if(height[left_pointer]<height[right_pointer]){
                max_area = max(max_area, height[left_pointer] * (right_pointer - left_pointer));
                left_pointer++;
            }else{
                max_area = max(max_area , height[right_pointer] * (right_pointer - left_pointer));
                right_pointer--;
            }
        }
        return max_area;
        
    }
};
