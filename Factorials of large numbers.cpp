/*
Problem Description : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0#
------------------------------------------------------------------------------------------------------------------------------
Given an integer, the task is to find factorial of the number.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found
 
Output:
Print the factorial of the number in separate line.
 
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
 
Example:
Input
3
5
10
2
 
Output
120
3628800
2
*/

//Code:
//--------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void fact(int x, vector<int>& res){
    int carry = 0;
    for(int i = 0 ; i  < res.size() ; i++){
        int val = res[i]*x + carry;
        res[i]= val%10;
        carry = val/10;
    }
    while(carry){
        res.push_back(carry%10);
        carry = carry/10;
    }
}
void factorial(int n, vector<int>& res){
    res.push_back(1);
    for(int i = 2 ; i<= n ; i++){
        fact(i, res);
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> res;
	    factorial(n, res);
	    for(int i = res.size()-1;i>=0 ; i--)
	        cout<<res[i];
	    cout<<"\n";
	}
	return 0;
}
