/*
Problem Description 
--------------------------------------------------------
Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. 
Find these two numbers.
Examples:

 
Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 
2 is missing and 3 occurs twice 

Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1
*/
//Solution approach : 
---------------------------------------------------------------------

/*
https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
one pass solution:
Let x be the missing and y be the repeating element.
Let N is the size of array.
Get the sum of all numbers using formula S = N(N+1)/2
Get product of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
Iterate through a loop from i=1….N
S -= A[i]
Sum_Sq -= (A[i]*A[i])
It will give two equations
x-y = S – (1)
x^2 – y^2 = Sum_sq
x+ y = (Sum_sq/S) – (2)

Time Complexity: O(n)
*/
Code:
---------------------------------------------------------
#include <bits/stdc++.h> 

using namespace std; 

vector<int>repeatedNumber(const vector<int> &A) { 
	long long int len = A.size(); 
	long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6; 
	long long int missingNumber=0, repeating=0; 
	
	for(int i=0;i<A.size(); i++){ 
	Sum_N -= (long long int)A[i]; 
	Sum_NSq -= (long long int)A[i]*(long long int)A[i]; 
	} 
	
	missingNumber = (Sum_N + Sum_NSq/Sum_N)/2; 
	repeating= missingNumber - Sum_N; 
	vector <int> ans; 
	ans.push_back(repeating); 
	ans.push_back(missingNumber); 
	return ans; 	
} 
int main(void){ 
		std::vector<int> v = {4, 3, 6, 2, 1, 6,7}; 
	vector<int> res = repeatedNumber(v); 
	for(int x: res){ 
		cout<< x<<" "; 
	} 
	cout<<endl; 
} 
