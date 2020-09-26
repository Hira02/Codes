/*
Problem Description  : (LC 84)
---------------------------------------------------------------------------------
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of
 largest rectangle in the histogram.
https://assets.leetcode.com/uploads/2018/10/12/histogram.png
 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/
//Code : https://www.youtube.com/watch?v=ZmnqCZp9bBs&ab_channel=TusharRoy-CodingMadeSimple
//---------------------------------------------------------------------------------------------------------
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> Stack;
        int i = 0 ; 
        while(i<heights.size()){
            if(Stack.empty() || heights[Stack.top()]<=heights[i]){
                Stack.push(i++);
            }else{
                int top = Stack.top();
                Stack.pop();
                int currArea = heights[top] *(Stack.empty() == true?i:(i - Stack.top()-1));
                maxArea = max(maxArea, currArea);
            }
        }
        while(!Stack.empty()){
            int top = Stack.top();
                Stack.pop();
                int currArea = heights[top] *(Stack.empty() == true?i:(i - Stack.top()-1));
                maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};