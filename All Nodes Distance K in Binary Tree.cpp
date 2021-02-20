/*

Problem Description : (LC 863)
------------------------------------------------
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.
https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png


Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.

*/

#1:

COde:
----------------------------------------
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
    void undirectedGraphCreate(TreeNode* root, map<int, TreeNode*> &m, TreeNode* parent){
        if(root == NULL)
            return ;
        if(parent != NULL){
            m[root->val] = parent;
            cout<<"root->val : "<<root->val<<" parent"<<parent->val<<"\n";
        }
        undirectedGraphCreate(root->left, m, root);
        undirectedGraphCreate(root->right, m, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        map<int, TreeNode*> m;
        map<int, int> seen;
        m[root->val] = NULL;
        undirectedGraphCreate(root, m, NULL);
        queue<TreeNode*> q;
        q.push(target);
        seen[target->val] = 1;
        int currLevel = 0;
        while(!q.empty()){
            if(currLevel == K){
                break;
            }else{
                int size = q.size();
                for(int i = 0 ; i < size ; i++){
                    TreeNode* temp = q.front();
                    cout<<"queue values : "<<temp->val<<"\n";
                    q.pop();
                    if(temp->left){
                        if(seen.find(temp->left->val) == seen.end()){
                            seen[temp->left->val] = 1;
                            q.push(temp->left);
                        }
                    }
                    if(temp->right){
                        if(seen.find(temp->right->val) == seen.end()){
                            seen[temp->right->val] = 1;
                            q.push(temp->right);
                        }
                    }
                    TreeNode* parent = m[temp->val];
                    if(parent){
                    cout<<"parent->val : "<<parent->val<<"\n";
                    if(seen.find(parent->val) == seen.end()){
                        seen[parent->val] = 1;
                        q.push(parent);
                    }
                    }
                }
                currLevel++;
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* val = q.front();
            res.push_back(val->val);
            q.pop();
        }
        return res;
        
    }
};

#2:;
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        parent_map[root] = NULL;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                parent_map[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent_map[curr->right] = curr;
            }
        }
        q.push(target);
        visited[target] = true;
        int currLevel = 0;
        while(!q.empty()){
            if(currLevel++ == K)
                break;
            int size = q.size();
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                 if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                 if(parent_map[curr] && !visited[parent_map[curr]]){
                    q.push(parent_map[curr]);
                    visited[parent_map[curr]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
        
    }
};
