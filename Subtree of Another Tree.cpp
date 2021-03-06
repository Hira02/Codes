Problem Description:
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is 
a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
 
 
 Code:
 -------------------------------------------------------------
 sol:1
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
bool compare(TreeNode*a, TreeNode*b){
        if(a == NULL && b == NULL)
            return true;
        if(a == NULL || b == NULL)
            return false;
        return (a->val == b->val) && compare(a->left, b->left) && compare(a->right, b->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL)
            return false;
        return s && (compare(s, t) || isSubtree(s->left,t) || isSubtree(s->right,t));
    }
};

sol 2:
------------------------------------------------------------------------------------
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
    bool result = false;
    bool fun(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL)
            return true;
        if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
            return false;
        return (root1->val == root2->val) && fun(root1->left, root2->left) &&
            fun(root1->right, root2->right);
    }
    void util(TreeNode* s, TreeNode* t){
        if(s == NULL)
            return ;
        if(s->val == t->val && result == false){
           result = fun(s,t);
            cout<<result;
        }         
        util(s->left,t);
        util(s->right, t);  
        
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if((s == NULL && t != NULL) || (s != NULL && t == NULL))
            return false;
        if(s == NULL && t == NULL)
            return true;
        util(s, t);
        return result;
    }
};
