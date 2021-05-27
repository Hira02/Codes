/*
Problem Description : (LC 3)
https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0
---------------------------------------------------------------------------
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is str.

Output:

Print the length of longest substring.

Constraints:

1 ≤ T ≤ 20
1 ≤ str ≤ 50

Example:

Input:
2
geeksforgeeks
qwertqwer

Output:
7
5
*/
//Code:
//-----------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    unordered_set<char> Map;
	    int a_pointer = 0;
	    int b_pointer = 0;
	    int res = 0;
	    while(b_pointer<s.length()){
	        if(Map.find(s[b_pointer]) == Map.end()){
	           
	            Map.insert(s[b_pointer]);
	             b_pointer++;
	             int mapSize = Map.size();
	            res = max(mapSize, res);
	            
	        }else{
	            Map.erase(s[a_pointer]);
	            a_pointer++;
	        }
	    }
	    cout<<res<<"\n";
	}
	return 0;
}
 


#java
class Solution {
    public int lengthOfLongestSubstring(String s) {
            int l = 0;
            int maxLen = 0;
            // Vector<Integer> cnt = new Vector<>(256);
            int cnt[] = new int[256];
            for(int i = 0 ; i < s.length() ; i++){
                    l = cnt[s.charAt(i)]>0 ? Math.max(l, cnt[s.charAt(i)]):l;
                    cnt[s.charAt(i)] = i+1;
                    maxLen = Math.max(maxLen, i-l+1);
            }
        return maxLen;
    }
}
