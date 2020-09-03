Problem Description:(LC:865)
----------------------
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]

Code:
-------------------------------------
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
    int getHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(getHeight(root->left), getHeight(root->right))+1;
    }
    TreeNode* helper(TreeNode* root, int level, int height){
        if(root == NULL){
            return NULL;
        }
        if(level == height)
            return root;
        TreeNode* left = helper(root->left, level+1, height);
        TreeNode* right = helper(root->right, level+1, height);
        if(left && right)
            return root;
        return (left)?left:right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL)
            return NULL;
        int height = getHeight(root);
        cout<<height;
        return helper(root, 1, height);
    }
};
