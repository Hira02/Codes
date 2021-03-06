/*
Problem Description : (LC 337)
-----------------------------------------------------------------------------------------------
The thief has found himself a new place for his thievery again. There is only one entrance to this area,
 called the "root." Besides the root, each house has one and only one parent house. After a tour,
  the smart thief realized that "all houses in this place forms a binary tree". It will automatically 
  contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
//Code:
//-------------------------------------------------------------------------------------------------
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
#1:
class Solution
{
public:
    vector<int> helper(TreeNode *root)
    {
        if (root == NULL)
            return vector<int>{0, 0};
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        vector<int> res(2, 0);
        res[0] = root->val + left[1] + right[1];
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }
    int rob(TreeNode *root)
    {
        vector<int> ans = helper(root);
        return max(ans[0], ans[1]);
    }
};

#2 : Faster

class Solution {
public:
 pair<int, int> dfs(TreeNode* node) {
        if (node == NULL)
            return make_pair(0,0);
        
        pair<int, int> l = dfs(node->left);
        pair<int, int> r = dfs(node->right);
        
        int steal = node->val + l.second + r.second;
        int n_steal = l.first + r.first;
        return make_pair(max(steal, n_steal), n_steal);
    };
    
    int rob(TreeNode* root) {
        return dfs(root).first;
    }
};
