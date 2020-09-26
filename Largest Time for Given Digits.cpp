/*
Problem Description  : (LC 949)
------------------------------------------------------------------------------------------
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9
*/

//Code:
//----------------------------------------------------------------------------------------------------------
class Solution {
public:
    void createPermutation(vector<int>& A, vector<string>& arr, vector<int>& visited, string currStr){
        if(currStr.size() == A.size()){
            arr.push_back(currStr);
            return ;
        }
        for(int i = 0 ; i < A.size() ; i++){
            if(!visited[i]){
                visited[i] = true;
                createPermutation(A, arr, visited, currStr + to_string(A[i]));
                visited[i] = false;
            }
        }
    }
    bool isValid(string str){
        if(str[0]>'2')
            return false;
        if(str[0] == '2' && str[1]>='4')
            return false;
        if(str[2]>'5')
            return false;
        return true;
    }
    string largestTimeFromDigits(vector<int>& A) {
        string res = "";
        int n = A.size();
        if(n == 0)
            return res;
        vector<string> arr;
        vector<int> visited(4, false);
        createPermutation(A, arr, visited,"");
        sort(arr.rbegin(), arr.rend());
        for(auto c : arr){
            // cout<<c<<" ";
            if(isValid(c)){
                res = c;
                break;
            }
        }
        if(res != ""){
            res.insert(res.begin()+2,':');
        }
        return res;
    }
};
