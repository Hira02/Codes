/*
Problem Description : https://practice.geeksforgeeks.org/problems/match-specific-pattern/1
-----------------------------------------------------------------------------------------------------------
Given a dictionary of words and a pattern. Every character in the pattern is uniquely mapped to a character in the dictionary. 
Find all such words in the dictionary that match the given pattern. 

Input:
The first line of input contains an integer T denoting the number of test cases. Each testcase contains 3 lines. The first line 
contains an integer N denoting the number of strings in the dictionary, second-line N space-separated strings denoting the strings of the dictionary. The third line contains pattern.

Output:
The output for each test case will be the space-separated strings that matches the given pattern in lexicographical order.

User Task:
You don't need to read input or print anything. Your task is to complete the function findMatchedWords() which takes an array of 
strings dict[] consisting of the words in the dictionary and a string, Pattern and returns an array of strings consisting of all 
the words in the dict[] that match the given Pattern. 

Expected Time Complexity: O(N*K) (where K is the length of the pattern).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 100
1 <= N <= 10

Input
1
4
abb abc xyz xyy
foo

Output
abb xyy

Explanation
Testcase 1: In the above test case xyy and abb have the same character at index 1 and 2 like the pattern.

*/

//Code:
//---------------------------------------------------------------------------------------------------------------
string encode(string str){// helper function
    unordered_map<char, int> Map;
    string res = "";
    int index = 1;
    for(int i = 0 ; i < str.length() ; i++){
        if(Map.find(str[i]) == Map.end())
        Map[str[i]] = index++;
        res+=to_string(Map[str[i]]);
    }
    return res;
}
vector<string> findMatchedWords(vector<string> dict,string pattern)//driver function
{
       //Your code here
       vector<string> res;
       int len = pattern.length();
       string pat = encode(pattern);
       for(auto c: dict){
           if(c.length() == len && encode(c) == pat)
           res.push_back(c);
       }
       return res;
       
}
//TC : O(n*k)
//SC : O(k)