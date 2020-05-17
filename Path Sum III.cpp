/*
Problem Description:
--------------------------------------
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11


*/

Code:
----------------------------------------------------
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
    int result = 0;
     int currSum = 0;
    void utilFun(TreeNode* root,int sum, int currSum){
        if(root == NULL)
            return ;
        currSum+=root->val;
        if(currSum == sum)
            result+=1;
        utilFun(root->left, sum, currSum);
        utilFun(root->right, sum, currSum);
    }
    void util(TreeNode* root, int sum){
        if(root == NULL)
            return ;
        utilFun(root, sum, 0);
        util(root->left, sum);
        util(root->right, sum); 
        
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
       
        util(root, sum);
        return result;
        
    }
};
TC : O(n*n)
SC: O(1) if fucntion call neglected else O(n*n)
