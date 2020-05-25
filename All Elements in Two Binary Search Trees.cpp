/*Problem Description  :(LC 1305)
---------------------------------------
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:
https://assets.leetcode.com/uploads/2019/12/18/q2-e1.png

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:
https://assets.leetcode.com/uploads/2019/12/18/q2-e5-.png

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].

*/
Code:
--------------------------------------------------------------------------

Approach 1:
--------------------------------------------------------------------------
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
    void inorder(TreeNode* root, vector<int> &res){
        if(root == NULL)
            return ;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    void sortedMerge(TreeNode* root1, TreeNode* root2, vector<int> &res){
        if(!root1 && !root2)
            return ;
        if(root1 == NULL){
            inorder(root2, res);
            return ;
        }
        if(root2 == NULL)
        {
            inorder(root1, res);
            return ;
        }
        TreeNode* temp1 = root1;
        TreeNode* temp2 = root2;
        TreeNode* prev1 = NULL;
        TreeNode* prev2 = NULL;
        while(temp1->left){
            prev1 = temp1;
            temp1 = temp1->left;
        }
        while(temp2->left){
            prev2 = temp2;
            temp2 = temp2->left;
        }
        cout<<temp1->val<<" "<<temp2->val<<"\n";
        if(temp1->val<=temp2->val){
            res.push_back(temp1->val);
            if(prev1 == NULL){
                sortedMerge(root1->right, root2,res);
            }else{
                prev1->left = temp1->right;
                sortedMerge(root1, root2,res);
            }
        }else{
            res.push_back(temp2->val);
            if(prev2 == NULL){
                sortedMerge(root1,root2->right, res);
            }else{
                prev2->left = temp2->right;
                sortedMerge(root1, root2, res);
            }
        }
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        sortedMerge(root1, root2, res);
        return res;
        
    }
};
//Link : https://www.geeksforgeeks.org/merge-two-bsts-with-constant-extra-space/?ref=rp

Approach: 2
---------------------------------------------------------------------------------------
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
    void inorder(TreeNode* root, vector<int> &res){
        if(root == NULL)
            return ;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    void helper(TreeNode* root1, TreeNode* root2, vector<int> &res){
        if(root1 != NULL && root2 == NULL){
            inorder(root1, res);
            return;
        }
        if(root1 == NULL && root2 != NULL){
            cout<<"here";
            inorder(root2, res);
            return;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* curr1 = root1;
        TreeNode* curr2 = root2;
        while(curr1 != NULL || curr2 != NULL || !s1.empty() || !s2.empty()){
            if(curr1 != NULL || curr2 != NULL){
                if(curr1 != NULL){
                    s1.push(curr1);
                    curr1 = curr1->left;
                }
                if(curr2 != NULL){
                    s2.push(curr2);
                    curr2 = curr2->left;
                }
            }else{
                if (s1.empty())  {  
                while (!s2.empty())  
                {  
                    curr2 = s2.top();
                    s2.pop();
                    curr2->left = NULL;  
                    inorder(curr2,res);  
                }  
                return ;  
            }  
            if (s2.empty()){  
                while (!s1.empty())  
                {  
                    curr1 = s1.top();
                    s1.pop();
                    curr1->left = NULL;  
                    inorder(curr1,res);  
                }  
                return ;  
            }  
                curr1 = s1.top();
                curr2 = s2.top();
                if(curr1->val<=curr2->val){
                    res.push_back(curr1->val);
                    s1.pop();
                    curr2 = NULL;
                    curr1 = curr1->right;
                }else{
                    res.push_back(curr2->val);
                    // res.push_back(curr2->val);
                    s2.pop();
                    curr1 = NULL;
                    curr2 = curr2->right;
                }
            }
        }
            
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> res;
        if(root1 == NULL && root2 == NULL)
            return res;
        helper(root1, root2, res);
        return res;
    }
};
//link : https://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space/




