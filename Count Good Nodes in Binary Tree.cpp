/*
Problem Description: (LC 1448)
------------------------------
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a 
value greater than X. Return the number of good nodes in the binary tree.
Example 1:
https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png
Input: root = [3,1,4,3,null,1,5]
Output: 4

Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

*/
//Code:
//-----------------------------------------------------------
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
    // int ans = 0;
    // int mn = INT_MIN;
    int dfs(TreeNode* root, int mn = INT_MIN){
         if(root == NULL)
            return 0;
       int ans = root->val>= mn;
        mn = max(mn, root->val);
        ans+=dfs(root->left,mn);
        ans+=dfs(root->right,mn);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root); 
        
    }
};
