/*
Problem Description : (LC 378) HARD
-----------------------------------------------------
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
*/
Code:
--------------------------------------------------------------
class Matrix{
  public : 
    int val;
    int row;
    int col;
    Matrix(int Val, int rowVal, int colVal){
        val = Val;
        row = rowVal;
        col = colVal;
    }
};
class myComp{
  public : 
    bool operator()(const Matrix &a, const Matrix &b){
        return a.val>b.val;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Matrix, vector<Matrix>, myComp> pq;
        for(int i = 0;i<matrix.size() ;i++){
            pq.push(Matrix(matrix[0][i], 0, i));
        }
        for(int i = 0 ; i < k -1; i++){
            Matrix top = pq.top();
            cout<<top.val<<"\n";
            pq.pop();
            int nextVal = (top.row<matrix.size()-1)?matrix[top.row+1][top.col]:INT_MAX;
            pq.push(Matrix(nextVal, top.row+1,top.col));
        }
        Matrix res = pq.top();
        return res.val;;
    }
};
//Solution approach : https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/
