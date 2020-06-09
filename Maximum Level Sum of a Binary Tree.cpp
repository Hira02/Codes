/*
Problem Description : (LC 1161)
---------------------------------------------
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:

https://assets.leetcode.com/uploads/2019/05/03/capture.JPG

Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
 

Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5
*/
Code:
-----------------------------------------------------------------------------
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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int resLevel = level;
        while(!q.empty()){
            int currSum = 0;
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* top = q.front();
                currSum+=top->val;
                q.pop();
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            if(currSum>maxSum){
                maxSum = currSum;
                resLevel = level;
            }
            // else if(currSum == maxSum){
            //     if(resLevel>level){
            //         resLevel = level;
            //     }
            // }
            level++;
        }
        return resLevel;
        
    }
};
