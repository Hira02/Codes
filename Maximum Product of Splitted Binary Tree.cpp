/*
Problem Description:(LC 1339)
--------------------------------------------------------------
Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.
https://assets.leetcode.com/uploads/2020/01/21/sample_1_1699.png
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

https://assets.leetcode.com/uploads/2020/01/21/sample_2_1699.png
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
Since the answer may be too large, return it modulo 10^9 + 7.


*/
Code:
--------------------------------------------------------------------
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
    long long  max_ = 0;
    int getSum(TreeNode* root){
        if(root == NULL)
            return 0;
        return getSum(root->left)+getSum(root->right)+root->val;
    }
    long long getProd(TreeNode* root, int totalSum){
        if(root == NULL)
            return 0;
        long long l= getProd(root->left, totalSum);
        long long r= getProd(root->right, totalSum);
        long long sum= (l+r)+root->val;
        long long product = ((totalSum-sum)*sum);
        max_ = max(max_, product);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int totalSum = getSum(root);
        // int maxProd = 0;
        getProd(root, totalSum);
        return (int)(max_%1000000007);
        
    }
};
