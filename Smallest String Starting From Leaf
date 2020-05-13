Problem Description : (LC 988)
--------------------------------------

Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z':
a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba". 
A leaf of a node is a node that has no children.)
Input: [0,1,2,3,4,3,4]
Output: "dba"
Input: [25,1,3,1,3,0,2]
Output: "adz"
Input: [2,2,1,null,1,0,null,0]
Output: "abc

Code:
------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void createNumber(TreeNode* root, string* res, string currString){
        if(root == NULL)
            return ;
         string s = string(1, (root->val)+'a');
        currString+=s;
        if(root->left == NULL && root->right == NULL){
             reverse(currString.begin(), currString.end());
            if((*res) == ""){
                (*res) = currString;
            }else{
               
                if(currString<(*res))
                    (*res) = currString;
            }
        }
        createNumber(root->left, res, currString);
        createNumber(root->right, res, currString); 
        
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root == NULL)
            return "";
       string res = "";
        string currString = "";
        createNumber(root, &res, currString);
      
        return res;
    }
};
