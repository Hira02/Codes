/*
Problem Description :
----------------------------------
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?


*/

Code:
-----------------------------------------------------------------
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* temp;
        // if(root->left)
        temp = root->left;
        // else
        //     temp = root->right;
        while(temp || !s.empty()){
            // if()
        while(temp){
            s.push(temp);
            temp = temp->left;
        }
            TreeNode* top = s.top();
            s.pop();
            cout<<top->val<<"\n";
            --k;
            if(k == 0)
                return top->val;
            temp = top->right;
        }
        return -1;
        
    }
};
TC : O(H+K)
SC : O(H+K)
