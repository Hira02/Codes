/*
Problem Description: (LC 1026)
-----------------------------------------------------
Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)
Example 1:

https://assets.leetcode.com/uploads/2019/09/09/2whqcep.jpg
Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.


*/
Code:
--------------------------------------------------------------------------------
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
    int traverse(TreeNode* root, int max_, int min_)
    {
        
        if (root == nullptr) {
            return max_-min_;
        }
        if (root->val > max_) {
            max_ = root->val;
        }
        if (root->val < min_) {
            min_ = root->val;
        }
        cout<<"root :"<<root->val<<" max :"<<max_<<" "<<" min :"<<min_<<"\n";
        return max(traverse(root->left, max_, min_), traverse(root->right, max_, min_));
    }
    int maxAncestorDiff(TreeNode* root) {
        return traverse(root, root->val, root->val);
        
    }
};
