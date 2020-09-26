/*
Problem Description : https://practice.geeksforgeeks.org/problems/remove-b-and-ac-from-a-given-string/0
------------------------------------------------------------------------------------------------------------------
Given a string, eliminate all “b” and “ac” in the string, replace them in-place and iterate over the string once.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string of length N.

Output:
Print the resultant substring after removing 'b' and 'ac' from string.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 200

Example:
Input:
2
acbac
aababc

Output:

aaac
*/

//Code:
//------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
string helper(string s){
    int len = s.length();
    int i = 0 , j = 0 ;
    string res = "";
    int state = 1;
    for(int i =  0 ; i < len ; i++){
        if(state == 1 && (s[i] != 'a' && s[i] != 'b')){
            res.push_back(s[i]);
        }
        if(state == 2 && s[i] != 'c'){
            res.push_back('a');
            if(s[i] != 'a' && s[i] !='b'){
                res.push_back(s[i]);
            }
        }
        state = (s[i] == 'a')?2:1;
    }
    if(state == 2)
    res.push_back('a');
    return res;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    cout<<helper(str)<<"\n";
	}
	return 0;
}
/*
Note : The above code works fine but for input "aacacc", it produces "ac", if the requiement is to not to have "ac" in  the o/p at all then
the code fails.
*/
// Updated version : 
void stringFilter(char *str) 
{ 
    int n = strlen(str); 
  
    int i = -1;  // previous character 
    int j = 0;   // current character 
  
    while (j < n) 
    { 
        /* check if current and next character forms ac */
        if (j < n-1 && str[j] == 'a' && str[j+1] == 'c') 
            j += 2; 
  
        /* if current character is b */
        else if (str[j] == 'b') 
            j++; 
  
        /* if current char is 'c && last char in output 
           is 'a' so delete both */
        else if (i >= 0 && str[j] == 'c' && str[i] == 'a') 
            i--,j++; 
  
        /* else copy curr char to output string */
        else
            str[++i] = str[j++]; 
    } 
    str[++i] = '\0'; 
}
//Source : GeeksForGeeks