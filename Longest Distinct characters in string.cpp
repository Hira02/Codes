/*
Problem Description : https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0
-----------------------------------------------------------------------------------------------------------------------
Given a string S, find length of the longest substring with all distinct characters.  For example, for input "abca", 
the output is 3 as "abc" is the longest substring with all distinct characters.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:
Print length of smallest substring with maximum number of distinct characters.
Note: The output substring should have all distinct characters.

Constraints:
1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:
Input:
2
abababcdefababcdab
geeksforgeeks

Output:
6
7

*/

//Code:
//--------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define NO_OF_CHARS 256 
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>> str;
	    int maxLen = 1;
	    vector<int> arr(NO_OF_CHARS, -1);
	    int start = 0, end = 0;
	    while(end<str.length()){
	         start = max(start, arr[str[end]]+1);
	         maxLen = max(maxLen, end - start +1);
	         arr[str[end]] = end;
	         end++;
	    }
	    cout<<maxLen<<"\n";
	}
	return 0;
}

#java
class Solution{
    static int longestSubstrDistinctChars(String S){
        // code here
        if(S.length() == 0)
            return 0;
        int arr[] = new int[256];
        int i = 0, j = 0;
        arr[S.charAt(0)-0] = 1;
        int res = 1;
        while(j< S.length()-1){
            if(arr[S.charAt(j+1)-0] == 0){
                arr[S.charAt(j+1)-0] = 1;
                j++;
                res = Math.max(res, j-i+1);
            }else{
                arr[S.charAt(i)-0]--;
                i++;
            }
        }
        return res;
        
    }
}