/*
Problem Description : https://practice.geeksforgeeks.org/problems/minimum-steps-to-get-desired-array/0
--------------------------------------------------------------------------------------------------------------
Consider an array with n elements and value of all the elements is zero. We can perform following operations on the array.
         1. Incremental operations: Choose 1 element from the array and increment its value by 1.
         2. Doubling operation: Double the values of all the elements of array.
Given an array of integers of size N. Print the smallest possible number of operations needed to change the array from 
all zeros to desired array.

Input:
The first line of input contains an integer T denoting the number of test cases.The first line of each test case is an
 integer N  where N is the size of array .
The second line of each test case contains N input A[i].

Output:
Print the smallest possible number of the operations needed to change the array from all zeros to desired array.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ A[i] ≤ 200

Example:
Input:
3
3
16 16 16
2 
2 3
2 
2 1
Output:
7
4
3

Explanation : 
In first test case, the output solution looks as follows. First apply an incremental operation to each element. T
hen apply the doubling operation four times. Total number of operations is 3+4 = 7

In second test case, to get the target array from {0, 0}, we first increment both elements by 1 (2 operations),
 then double the array (1 operation). Finally increment second element (1 more operation)  Total number of operations is 2+1+1 = 4

In third test case , one of the optimal solution is to apply the incremental operation 2 times to first and once 
on second element.Total number of operations is 1+1+1 = 3
*/
//Code:
//-------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int convert(vector<int>& arr, int n){
    
    int count = 0;
    while(1){
        int i;
        int zero = 0;
        for(i = 0 ; i < n ; i ++){
            if(arr[i] & 1){
                break;
            }else if(arr[i] == 0){
                zero++;
            }
        }
        if(zero == n)
        return count;
        if(i == n){
            for(int j = 0 ; j < n ; j++){
                arr[j] = arr[j]/2;
            }
            count++;
        }else{
            for(int j = i ; j<n ; j++){
                if(arr[j]&1){
                arr[j] = arr[j]-1;
                count++;
                }
            }
        }
        
    }
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
	        cin>> val;
	        arr.push_back(val);
	    }
	   cout<<convert(arr, n)<<"\n";
	}
	return 0;
}