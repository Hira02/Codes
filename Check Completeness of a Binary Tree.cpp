/*
Problem Description : (Lc 958)
----------------------------------------------------------------------------------------------------------------------
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:

https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:
https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png

Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000
*/
//Code:
//--------------------------------------------------------------------------------------------------------------------------------------------------------
#Iterative:

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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top->left){
                if(flag == true)
                    return false;
                q.push(top->left);
            }else
                flag = true;
            if(top->right){
                if(flag)
                    return false;
                q.push(top->right);
            }
            else
                flag = true;
        }
        return true;
    }
};


#Recursive:

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
    unsigned int countNode(TreeNode* root){
        if(root == NULL)
            return 0;
        return (1+ countNode(root->left) + countNode(root->right));
    }
    bool checkCompleteTree(TreeNode* root, unsigned int index, unsigned int nodeCount){
        if(root == NULL)
            return true;
        if(index>= nodeCount)
            return false;
        return checkCompleteTree(root->left, index*2+1, nodeCount) && checkCompleteTree(root->right, index*2+2, nodeCount);
    }
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return true;
        unsigned int nodeCount = countNode(root);
        return checkCompleteTree(root, 0, nodeCount);
    }
};
