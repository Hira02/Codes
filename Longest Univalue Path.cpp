/*
Problem Description: (LC 687)
--------------------------------------------------
Given a binary tree, find the length of the longest path where each node in the path has the same value. 
This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2


*/
Code:
--------------------------------------------------------------
class Solution {
    public:
     int arrowLength(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = arrowLength(node->left);
        int right = arrowLength(node->right);
        int arrowLeft = 0, arrowRight = 0;
        if (node->left != nullptr && node->left->val == node->val) {
            arrowLeft += left + 1;
        }
        if (node->right != nullptr && node->right->val == node->val) {
            arrowRight += right + 1;
        }
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
    int ans;
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        arrowLength(root);
        return ans;
    }
};
    solution link : https://leetcode.com/problems/longest-univalue-path/solution/
