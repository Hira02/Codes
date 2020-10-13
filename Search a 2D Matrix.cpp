/*
Problem Description : (LC 74)
-----------------------------------------------------------------------------------
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
//Code:
//------------------------------------------------------------------------------------------------
#1 : 
class Solution {
public:
    bool valueSearch(vector<vector<int>>& matrix, int rowValue, int target){
        int start = 0;
        int end = matrix[rowValue].size();
        while(start<end){
            int mid = start + (end - start)/2;
            if(matrix[rowValue][mid] == target)
                return true;
            if(matrix[rowValue][mid]<target){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        // cout<<row;
        if( row == 0||matrix[0].size() == 0)
            return false;
        for(int i = 0; i < row; i ++){
            if(matrix[i][matrix[i].size()-1]>= target){
                return valueSearch(matrix, i, target);
            }
        }
        return false;
    }
};
//TC : O(row * log(col))
 
 #2:  
 class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        
    
        int low=0;
        int high= m*n-1;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target) return true;
            else if(matrix[mid/m][mid%m]>target){
                high = mid-1;
            }
            else low=mid+1;
        }
        
        return false;
    }
};
//TC : O(log (row * col))
//But the execution time is almost same in both the cases