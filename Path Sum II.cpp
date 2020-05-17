/*
Problem Description: (LC 113)
------------------------------------
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,
    5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]


*/
code:
-----------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<vector<int>> &res, vector<int> set, int currSum, int sum){
        if(root == NULL)
            return ;
        set.push_back(root->val);
        currSum+=root->val;
        if(root->left == NULL && root->right == NULL){
            if(currSum == sum){
                res.push_back(set);
                set.clear();
                currSum = 0;
            }
            return ;
        }
        helper(root->left, res, set, currSum, sum);
        
        helper(root->right, res, set, currSum, sum);
         if(set.size()>0)
        set.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> set;
        if(root == NULL)
            return res;
        helper(root, res, set, 0,sum);
        return res;
        
    }
};
