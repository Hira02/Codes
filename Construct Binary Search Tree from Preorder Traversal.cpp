/*
Problem Description 
--------------------------------------------------
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
https://assets.leetcode.com/uploads/2019/03/06/1266.png
 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.

*/

#1 : TC : O(n*n)
Code:
---------------------------------------------------
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
    void createTree(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == NULL){
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }else{
                createTree(root->left, val);
            }
        }else{
            if(root->right == NULL){
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
            }else{
                createTree(root->right, val);
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            createTree(root, preorder[i]);
        }
        return root;
        
    }
};

#2 : TC : O(n)

Node* constructTreeUtil(int pre[], int size, int low, int high, int key, int *index){
    if((*index)>=size)
        return NULL;
    Node* root = NULL;
    if(key>low && key<high){
        root = newNode(key);
        (*index) = (*index)+1;
        if((*index)<size){
            root->left = constructTreeUtil(pre,size,  low, key, pre[*index], index);
        }
        if((*index)<size){
            root->right = constructTreeUtil(pre, size, key, high, pre[*index], index);
        }
    }
    // else
        return root;
}
Node* constructTree(int pre[], int size) {
    //code here
    int index = 0;
    return constructTreeUtil(pre, size, INT_MIN, INT_MAX, pre[index], &index);
}
