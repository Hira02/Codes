/*
Problem Description : 
--------------------------------------------------------------------
Given a string s, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.


Examples:

Input  : abbc
Output : 3
Subsequences are abc, abc and abbc

Input  : abcabc
Output : 7
Subsequences are abc, abc, abbc, aabc
abcc, abc and abc


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string s.

Output:
For each test case in a new line print the required output.

Constraints:
1<=T<=100
1<=Length of string <=100

Example:
Input:
2
abbc
abcabc
Output:
3
7
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
       getline(cin, str);
       int aCount = 0, bCount = 0, cCount = 0;
       for(int i = 0 ; i < str.length() ; i++){
           if(str[i] == 'a'){
               aCount = 1+2*aCount;
           }else if(str[i] == 'b'){
               bCount = aCount + 2*bCount;
           }else{
               cCount = bCount + 2*cCount;
           }
       }
    cout<<cCount<<"\n";
    }
}
