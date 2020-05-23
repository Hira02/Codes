/*
Problem Description : (LC 114)
----------------------------------------------
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


*/
Code:
-------------------------------------
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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return ;
        else{
            while(root!=NULL){
            if(root->left != NULL){
                TreeNode* temp = root->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
            }
        }
        
    }
};
