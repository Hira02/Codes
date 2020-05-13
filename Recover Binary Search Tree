Problem Description: (LC : 99)
------------------------------------
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Example 1:
Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
   
   Code:
   ----------------------------
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
    void helper(TreeNode* root, TreeNode** first, TreeNode** second, TreeNode** middle, TreeNode** prev){
        if(root == NULL)
            return ;
        helper(root->left, first, second, middle, prev);
        if((*prev) && root->val < (*prev)->val){
            if(!(*first)){
                (*first) = (*prev);
                (*middle) = root;
            }else{
                (*second) = root;
            }
        }
        (*prev) = root;
        helper(root->right, first, second, middle, prev);
    }
    void swap(int* a, int*b){
        int temp = (*a);
        (*a) = (*b);
        (*b) = temp;
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first;
        TreeNode* second;
        TreeNode* middle;
        TreeNode* prev;
        first = second = middle = prev = NULL;
        helper(root, &first, &second, &middle, &prev);
        if(first && second){
            swap(&(first->val), &(second->val));
        }
        else
            swap(&(first->val), &(middle->val));
        
    }
};


Suggestion Link : https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
