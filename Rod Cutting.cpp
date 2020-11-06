/*
Problem Description : https://practice.geeksforgeeks.org/problems/rod-cutting/0
---------------------------------------------------------------------------------------------------------
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array. 
Second line of every test case consists of price of ith length piece.

Output:
For each testcase, in a new line, print a single line output consists of maximum price obtained.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= Ai <= 100

Example:
Input:
1
8
1 5 8 9 10 17 17 20
Output:
22
*/
//Code:
//------------------------------------------------------------------------------------------------------------
#recursion : TLE
#include <bits/stdc++.h>
using namespace std;
int helper(vector<int>& arr, int n){
    if(n<=0)
    return 0;
    int maxV = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        maxV = max(maxV, arr[i] + helper(arr, n-1-i));
    }
    return maxV;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr;
	    for(int i = 0 ; i < n ; i++){
	        int val;
	        cin>>val;
	        arr.push_back(val);
	    }
	    cout<< helper(arr, n)<<"\n";
	}
	return 0;
}
# DP

#include <bits/stdc++.h>
using namespace std;
int helper(vector<int>& arr, int n){
    int dp[n+1] = {-1};
    dp[0] = 0;
    for(int i = 1; i<= n ;i++){
        for(int j = 0; j < i ; j++){
            dp[i] = max(dp[i], arr[j] + dp[i-1-j]);
        }
    }
    return dp[n];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr;
	    for(int i = 0 ; i < n ; i++){
	        int val;
	        cin>>val;
	        arr.push_back(val);
	    }
	    cout<< helper(arr, n)<<"\n";
	}
	return 0;
}