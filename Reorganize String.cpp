/*
Problem Description : (LC 767)
----------------------------------------------------------------
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/
Code:
------------------------------------------------------------------------
class Solution {
public:
    string reorganizeString(string s) {
        int arr[26]={0};
        for(int i = 0 ; i< s.length() ; i++){
            arr[s[i]-'a']++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(int i= 0 ; i< 26 ; i++){
            if(arr[i]>0)
            pq.push(make_pair(arr[i],i));
        }
        pair<int,int> prev = make_pair(-1,100);
        string res = "";
        while(!pq.empty()){
            pair<int,int> top = pq.top();
            cout<<top.first<<" "<<top.second<<"\n";
            pq.pop();
            char temp = top.second+'a';
            res = res+temp;
            if(prev.first>0){
                pq.push(prev);
            }
            top.first--;
            prev = top;
        }
        if(s.length() == res.length())
            return res;
        return "";
        
    }
};
// Suggestion : https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/
