/*
Problem Description : (LC 835)
---------------------------------------------------------------------------------------------
Two images A and B are given, represented as binary, square matrices of the same size.  
(A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), 
and place it on top of the other image.  After, the overlap of this translation is the number of positions that
 have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1
*/
//Code:
//--------------------------------------------------------------------------------------------------
    class Solution {
    public:
        vector<pair<int, int>> get_ones(vector<vector<int>>& mat){
        vector<pair<int, int>> vec;
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j <mat[i].size() ; j++){
                if(mat[i][j] == 1){
                    vec.push_back(make_pair(i, j));
                }
            }
        }
        return vec;
    }
        int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
            vector<pair<int, int>> a_ones = get_ones(A);
            vector<pair<int, int>> b_ones = get_ones(B);
            int totalCount =0 ;
            map<pair<int, int>, int> hash;
            for(auto p : a_ones){
                for(auto q : b_ones){
                    pair<int, int> storage = make_pair(p.first - q.first, p.second - q.second);
                    if(hash.count(storage)){
                        hash[storage]++;
                    }else{
                       hash[storage] = 1;
                    }
                    totalCount = max(totalCount, hash[storage]);
                }
            }
            return totalCount;
        }
    };