/*
Problem Desdription : (LC 85)
----------------------------------------------------------------------------------------------------------
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:

https://assets.leetcode.com/uploads/2020/09/14/maximal.jpg
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
 

Constraints:

rows == matrix.length
cols == matrix.length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/
//Code: 
//-------------------------------------------------------------------------------------------------
//Ref : https://www.youtube.com/watch?v=g8bSdXCG-lA&ab_channel=TusharRoy-CodingMadeSimple
class Solution {
public:
    int findHistogramArea(vector<int>& arr){
        stack<int> Stack;
        int i = 0 ;
        int maxArea = 0;
        while(i<arr.size()){
            if(Stack.empty() || arr[Stack.top()]<= arr[i]){
                Stack.push(i++);
            }else{
                int top = Stack.top();
                Stack.pop();
                int currArea = arr[top]*((Stack.empty() == true)?i :(i - Stack.top()-1));
                maxArea = max(maxArea, currArea);
            }
        }
        while(!Stack.empty()){
            int top = Stack.top();
                Stack.pop();
                int currArea = arr[top] *(Stack.empty() == true?i:(i - Stack.top()-1));
                maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        
        vector<int> histogram(col, 0);
        int maxArea = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int val = matrix[i][j]-'0';
                if(val == 0)
                    histogram[j] = 0;
                else
            histogram[j] += val;
        }
            int currRowArea = findHistogramArea(histogram);// using histogram conept
            // cout<<currRowArea<<"\n";
            maxArea = max(maxArea, currRowArea);
      }
        return maxArea;
    }
};
