/*Problem Description : (LC 103)
-------------------------------------------------------------------------------------------------------------------
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/

Code:1
--------------------------------------------------------------------------------------------------------------
//Using two stack
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> curr;
        stack<TreeNode*> next;
        bool dir = false;
        curr.push(root);
        vector<int> temp;
        while(!curr.empty()){
            TreeNode* top = curr.top();
            curr.pop();
            temp.push_back(top->val);
            if(!dir){
                if(top->left){
                    next.push(top->left);
                }
                 if(top->right){
                    next.push(top->right);
                }
                
            }else{
                if(top->right){
                    next.push(top->right);
                }
                if(top->left){
                    next.push(top->left);
                }
            }
            if(curr.size() == 0){
                ans.push_back(temp);
                dir = !dir;
                temp.clear();
                swap(curr, next);
            }
        }
        return ans;

        
        
    }
};
--------------------------------------------------------------------------------------------------------------------------------------
Code:2
// Using one queue
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> res;
        queue<TreeNode* > q;
         bool direction = false;
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> set;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                // set.push_back(temp->val);
                q.pop();
                if(direction == true)
                 set.insert(set.begin(), temp->val);
                else
                    set.push_back(temp->val);              
                    
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }                  
                
            }
            direction = !direction;
            res.push_back(set);
            set.clear();
        }
        // reverse(res.begin(), res.end());
        // util(root, res);
        return res;
        
    }
    
};
