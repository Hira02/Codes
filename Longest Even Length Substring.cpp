/*
Problem Description : https://practice.geeksforgeeks.org/problems/longest-even-length-substring/0
--------------------------------------------------------------------------------------------------------------------
For given string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.
 

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string string of length N.

Output:

Print length of the longest substring of length 2k such that sum of left k elements is equal to right k elements and if there is no such substring print 0.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input:
2
000000
1234123

Output:
6
4  
*/

//Code:
//-------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	   string str;
	   cin>>str;
	   int maxLen = 0;
	   for(int i = 0 ; i < str.length()-1 ; i++){
	       int left = i;
	       int right = i+1;
	       int leftSum = 0;
	       int rightSum = 0;
	       while(left>=0 && right < str.length()){
	           leftSum+=str[left]-'0';
	           rightSum += str[right]-'0';
	           if(leftSum == rightSum)
	           maxLen = max(maxLen , (right-left+1));
	           right++;
	           left--;
	       }
	   }
	   cout<<maxLen<<"\n";
	    
	}
	return 0;
}
//TC : O(n^2)
//SC  : O(1)