/*
Problem Description:(LC 112)
---------------------------------
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
//code:
//---------------------------------------
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
    bool helper(TreeNode* root, int sum, int currSum){
        if(root == NULL)
            return false;
        currSum+=root->val;
        if(root->left == NULL && root->right == NULL){
            if(currSum == sum)
                return true;
        }
        return helper(root->left, sum , currSum) || helper(root->right, sum, currSum);
            
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        // if(sum == 0 && root == NULL)
        //     return false;
            // return true;
        int currSum = 0;
        return helper(root,sum,currSum);
        
    }
};
//TC : O(n);
//SC : O(1) // if recursion stack ignored
