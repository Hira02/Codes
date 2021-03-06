/*
Problem Description  : GFG
---------------------------------------------------------------------
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a string, which contains only I's and D's in capital letter.

Output:
Print the minimum number following that pattern.

Constraints:
1 ≤ T ≤ 100
1 ≤ Length of String ≤ 8

Example:
Input
5
D
I
DD
IIDDD
DDIDDIID

Output
21
12
321
126543
321654798

*/

//Code:
//-----------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
string convert(string str){
    string result = "";
    stack<int> Stack;
    for(int i = 0 ; i <= str.length() ; i++){
        Stack.push(i+1);
        if(i == str.length() || str[i] == 'I'){
            while(!Stack.empty()){
                int top = Stack.top();
                result+=to_string(top);
                Stack.pop();
            }
        }
    }
    return result;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>> str;
	    cout<<convert(str)<<"\n";
	}
	return 0;
}