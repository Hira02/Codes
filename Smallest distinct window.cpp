/*
Problem Description :  https://practice.geeksforgeeks.org/problems/smallest-distant-window/0
----------------------------------------------------------------------------------------------------------------
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string S.

Output:
For each test case in a new line print the length of the smallest such string.

Constraints:
1 <= T <= 100
1 <= |S| <= 105

Example:
Input:
2
aabcbcdbca
aaab

Output:
4
2

Explanation:
Testcase 1: Smallest window size is 4 which is of "dbca" which consists all characters of the string.


*/
//Code:
//--------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHARS = 256; 
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	   // string t;
	    cin>>str;
	    int n = str.length();
    int dist_count = 0; 
    bool visited[MAX_CHARS] = { false }; 
    for (int i = 0; i < n; i++) { 
        if (visited[str[i]] == false) { 
            visited[str[i]] = true; 
            dist_count++; 
        } 
    } 
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    int count = 0; 
    int curr_count[MAX_CHARS] = { 0 }; 
    for (int j = 0; j < n; j++) { 
        curr_count[str[j]]++; 
        if (curr_count[str[j]] == 1) 
            count++; 
        if (count == dist_count) { 
            while (curr_count[str[start]] > 1) { 
                if (curr_count[str[start]] > 1) 
                    curr_count[str[start]]--; 
                start++; 
            } 
            int len_window = j - start + 1; 
            if (min_len > len_window) { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
	    cout<<min_len<<"\n";
	    
	}
	return 0;
}