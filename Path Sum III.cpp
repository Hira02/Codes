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
      #1:
      
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
      
      #2:
      
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
    void helper(TreeNode* root, unordered_map<int, int>& Map, int sum, int currSum, int * count){
        if(root == NULL)
            return ;
        currSum+=root->val;
        if(Map.find(currSum - sum) != Map.end()){
            (*count) += Map[currSum - sum];
        }
        Map[currSum]+=1;
        helper(root->left, Map, sum, currSum, count);
        helper(root->right, Map, sum, currSum, count);
        Map[currSum]-=1;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> Map;
        Map[0] = 1;
        int currSum = 0;
        int count = 0;
        helper(root, Map, sum, currSum,  &count);
        return count;
    }
};
//TC : O(n)
//TC : O(n) // auxiliary space for map
