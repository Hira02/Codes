/*
Problem Description: ( LC 212) HARD
-----------------------------------------------------------------------------
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.

*/

Code:
----------------------------------------------------------------------------------
class Trie{
  public : 
    bool isWord;
    Trie* children[26];
    Trie(){
        isWord = false;
        for(int i = 0 ; i < 26 ; i++)
            children[i] = NULL;
    }
};
class Solution {
public:
    bool checkAllWord(vector<vector<char>>& board, int i, int j,Trie* root,  vector<vector<bool>>& visited, string& str, vector<string>& ans){
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size()||visited[i][j] || root->children[board[i][j]-'a'] == NULL)
            return false;
        root = root->children[board[i][j]-'a'];
        str.push_back(board[i][j]);
        visited[i][j]=true;
        if(root->isWord == true){
            cout<<str<<" ";
            ans.push_back(str);
            root->isWord = false;
            // return true;
        }
                
        
        if(checkAllWord(board, i-1, j, root, visited, str, ans) || checkAllWord(board, i+1, j, root, visited, str, ans) || checkAllWord(board, i, j+1, root, visited, str, ans) || checkAllWord(board, i, j-1, root, visited, str, ans))
            return true;
        visited[i][j]=false;
        str.pop_back();
        return false;
        
    }
    void createTrie(Trie** root, string word){
        Trie* node = (*root);
        for(int i = 0 ; i < word.length() ; i++){
            if(node->children[word[i]-'a'] == NULL){
                node->children[word[i]-'a'] = new Trie();
            }
            node = node->children[word[i]-'a'];
        }
        node->isWord = true;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        int wordsSize = words.size();
         vector<string> ans;              
        vector<vector<bool>> visited;
        visited.resize(m,vector<bool>(n, false));
        Trie* root = new Trie();
        for(int i = 0 ; i < wordsSize ; i++){
            createTrie(&root, words[i]);
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n  ; j++){
                string str = "";
                if(root->children[board[i][j] - 'a'] != NULL )
                    checkAllWord(board, i, j, root,visited, str, ans);
                    // ans.push_back(str);
                    
            }
        }
        return ans;
        
    }
};
