/*
Problem Description: (LC 654)
---------------------------------------------
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1



*/
Code:
---------------------------------------------------------
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
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l>r)
            return nullptr;
        int maxElement = INT_MIN;
        int maxIndex = -1;
        for(int  i =l ; i <= r; i++){
            if(maxElement<nums[i]){
                maxElement = nums[i];
                maxIndex = i;
            }
        }
      TreeNode* root = new TreeNode(maxElement);
        root->left = helper(nums, l, maxIndex-1);
        root->right = helper(nums, maxIndex+1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // TreeNode* root = new TreeNode(-1);
       return  helper(nums, 0, nums.size()-1);
        // return root;
    }
};
