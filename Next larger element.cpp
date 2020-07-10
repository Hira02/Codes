/*
Problem Description : GFG
----------------------------------------------------------------------------------------------------
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. 
The first line contains an integer N denoting the size of the array. The Second line of each test case contains
N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.
*/
Code:
-------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void helper(vector<long>& arr){
    stack<pair<long, int>> Stack;
    int index = 0;
    Stack.push(make_pair(arr[0],0));
    for(int i = 1 ; i < arr.size() ; i++){
        pair<long, int> top = Stack.top();
        
        while(!Stack.empty() && top.first<arr[i]){
            // cout<<Stack.top().first<<" ";
            Stack.pop();
            arr[top.second] = arr[i];
            if(Stack.size()>0)
            top = Stack.top();
        }
        Stack.push(make_pair(arr[i],i));
    }
    while(!Stack.empty()){
        pair<long, int> top = Stack.top();
        arr[top.second] = (long)-1;
        Stack.pop();
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t){
	    int n;
	    cin>>n;
	    vector<long> arr(n);
	    for(int i = 0 ; i < n ; i ++){
	        cin>>arr[i];
	    }
	    helper(arr);
	    for(int i = 0 ; i < n ; i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<"\n";
	    t--;
	}
	return 0;
}
