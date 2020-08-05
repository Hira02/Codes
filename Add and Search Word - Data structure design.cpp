/*
Problem Description : (LC 221)
-------------------------------------------------------------------------------------------
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . 
means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    
    class Trie{
          public: 
       bool  isWord;
        Trie* children[26];      
        Trie(){
            for(int i = 0 ; i < 26 ; i++){
              children[i] = NULL;
            }
            // root->isWord = true;
            isWord = false;
        }
    };
      Trie* root_;
    WordDictionary() {
        root_ = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* temp = root_;
        for(int i = 0 ; i < word.length() ; i++){
            int val = word[i] - 'a';
            if(temp->children[val] == NULL){
                temp->children[val] = new Trie();
            }
            temp = temp->children[val];
        }
        temp->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
     bool searchWordRecur(string word, int index, Trie* root){
        // cout<<index<<" " <<word[index]<<" ";
        if(index == word.length()) {
            return root->isWord;
        }
            if(word[index] != '.'){
                int val = word[index] - 'a';
                // cout<<val<<" ";
                return root->children[val]!= NULL && searchWordRecur(word, index+1, root->children[val]);
            }else{
                for(int i = 0 ; i < root->children ; i++){
                    if(root->children[i] != NULL){
                        if(searchWordRecur(word, index+1, root->children[i]))
                            return true;
                    }
                }
            }
        // }
        return false;
    }
    bool search(string word) {
        Trie* temp = root_;
        return searchWordRecur(word, 0, temp);
    }
   
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */