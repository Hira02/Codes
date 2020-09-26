/*
Problem Description :  https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
-----------------------------------------------------------------------------------------------------------------------
Given a sorted dictionary (array of words) of an alien language, find order of characters in the language.
Examples:

Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
Output: Order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa" 
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input:  words[] = {"caa", "aaa", "aab"}
Output: Order of characters is 'c', 'a', 'b'
*/
//Code:
//---------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int distWordCheck(vector<string>& words){
    unordered_set<char> chars;
    for(int i = 0 ; i < words.size() ; i++){
        for(int j = 0 ;  j < words[i].length() ; j++){
            if(chars.find(words[i][j]) == chars.end()){
                chars.insert(words[i][j]);
            }
        }
    }
    return chars.size();
}
void topoSort(unordered_map<int, vector<int>>& Adj, vector<bool>& visited, int node, stack<int>& Stack){
    visited[node] = true;
    for(auto t = Adj[node].begin() ; t!=Adj[node].end() ; t++){
        if(visited[(*t)] == false)
            topoSort(Adj, visited, *t, Stack);
    }
    Stack.push(node);
}
string arrangeWord( vector<string>& words, int k) {
    // Your code here
     unordered_map<int, vector<int>> Adj;
    for(int i = 0 ; i < words.size()-1; i++){
        for(int j = 0 ; j < min(words[i].length(), words[i+1].length());j++){
            if(words[i][j] != words[i+1][j]){
                Adj[words[i][j]-'a'].push_back(words[i+1][j]-'a');
                break;
            }
        }
        // cout<<"\n";
    }
    vector<bool> visited(k, false);
    stack<int> Stack;
    for(int t = 0 ; t < k ; t++){
        if(visited[t] == false){
            topoSort(Adj, visited, t,Stack);
        }
    }
    string ans = "";
    while(!Stack.empty()){
        int top = Stack.top();
        ans+=top+'a';
        Stack.pop();
    }
    // return vector<char> (Stack.begin(), Stack.end());
    return ans;
}
int main(){
    vector<string> words = {"baa", "abcd" ,"abca", "cab", "cad"};
    // int n;
    // cin>>n;
    // for(int i = 0 ; i < n ; i++){
    //     string str;
    //     words.push_back(str);
    // }
    int alpha = distWordCheck(words);
    cout<<alpha<<"\n";
    string arrange = arrangeWord(words, alpha);
    // for(int i = 0 ; i < arrange.size() ; i++){
    //     cout<<arrange[i]<<" ";
    // }
    cout<<arrange;
return 0;

}