/*
Problem Description  :(LC 1457)
--------------------------------------------------
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least 
one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

Example 1:
https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png


Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: 
the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic
paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 2:
https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png


Input: root = [2,1,1,1,3,null,null,null,null,null,1]
Output: 1 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes:
the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since 
[2,1,1] can be rearranged in [1,2,1] (palindrome).
Example 3:

Input: root = [9]
Output: 1
*/
Code:
#1:
----------------------------------------
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
    int count = 0;
    bool isPalindrom(map<int,int> &m){
       // std:: map<int,int> :: itr;
        int temp = 0;
        for(auto itr:  m){
            cout<<itr.first<<" ";
            if(itr.second %2 != 0)
                temp++;
                
        }
        cout<<"\n";
        return (temp<2);
    }
    void helper(TreeNode* root, map<int,int> &m){
        if(root == NULL)
            return;
         m[root->val]++;
        if(root->left == NULL && root->right == NULL){
            bool check = isPalindrom(m);
            if(check)
                count++;
           // m.erase(root->val);
            // return ;
        }
        helper(root->left, m);
        helper(root->right, m);
        m[root->val]--;
       
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int>m;
        helper(root,m);
        return count;
        
    }
};

#2 : 
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
    void helper(TreeNode* root, vector<int> store, int* count){
        if(root == NULL)
            return ;
        store[root->val-1]++;
        if(root->left)
            helper(root->left, store, count);
        if(root->right)
            helper(root->right, store, count);
        if(root->left == NULL && root->right == NULL){
            int cnt = 0;
            for(int i = 0; i < 9 ; i++){
                if(store[i]%2 == 1)
                    cnt++;
            }
            if(cnt<=1)
                (*count)++;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL)
            return  0;
        vector<int> store(9,0);
        int count = 0;
        helper(root, store, &count);
        return count;
    }
};
