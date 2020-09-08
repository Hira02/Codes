/*
Problem Description : GFG
---------------------------------------------------------------------------
Given a boolean 2D array where each row is sorted. Find the row with the maximum number of 1s.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains n and m, where n is the number of rows and m is the number of columns. 
The second line of each test case contains the array elements.

Output:
Print the row with the maximum number of 1s.

Constraints:
1 ≤ T ≤ 50
1 ≤ n,m ≤ 103

Example:
Input:
2
4 4
0 1 1 1 0 0 1 1 1 1 1 1 0 0 0 0
2 2
0 0 1 1

Output:
2
1

Explanation :
Testcase 1 : Row 2 is having maximum number of 1s (0-based indexing).
*/

Code:
----------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int findIndex(vector<int>& arr,  int start, int end){
    if(start<=end){
    int mid = start + (end - start)/2;
    if((mid==0 || arr[mid-1] == 0) && arr[mid] == 1)
    return mid;
    else if(arr[mid] == 0){
        return findIndex(arr,  mid+1, end);
    }else {
        return findIndex(arr, start, mid-1);
    }
    }
    return -1;
}
int findMax(vector<vector<int>>& arr){
    int max_count= 0;
    int max_row = -1;
    for(int i = 0 ; i < arr.size() ; i++){
        int index = findIndex(arr[i], 0, arr[i].size()-1);
        if(index != -1 && C-index>max_count){
            max_count = C-index;
            max_row = i;
        }
        
    }
    return max_row;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t){
	    int m, n;
	    cin>>m>>n;
	    vector<vector<int>> arr(m, vector<int>(n));
	    for(int i = 0 ; i < m ; i++){
	        for(int j = 0 ; j < n ; j++){
	            cin>>arr[i][j];
	        }
	    }
	    cout<<findMax(arr);
	    cout<<"\n";
	    t--;
	}
	return 0;
}
