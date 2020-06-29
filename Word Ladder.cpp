/*
Problem Description : (LC 127)
-------------------------------------------------------------------------
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/

Code:
-----------------------------------------------------------------------------------------------
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> indexing;
        for(auto c : wordList){
            indexing[c] = 1;
        }
        if(indexing.find(endWord) == indexing.end())
            return 0;
        queue<string> Queue;
        Queue.push(beginWord);
        int level = 1;
        while(!Queue.empty()){
            int size = Queue.size();
            for(int  i = 0 ; i < size ; i++){
                string top = Queue.front();
                // cout<<top<<" ";
                Queue.pop();
                // string currentString = "";
                for(int k =  0 ;  k < top.length() ; k++){
                    char originalWord = top[k];
                    for(char j = 'a' ; j<= 'z' ; j++){
                      if(top[k] == j) continue;
                      top[k] = j;
                        // cout<<top<<" ";
                        if(top == endWord) return level+1;
                        if(indexing.find(top) != indexing.end()){
                            // cout<<top<<" ";
                            Queue.push(top);
                            indexing.erase(top);
                        }
                    }
                    top[k] = originalWord;
                }
            }
            level++;
        }
        return 0;
        
    }
};
