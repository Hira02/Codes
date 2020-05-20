/*
Problem Description : (LC 559)
--------------------------------------------------------
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:
https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Example 2:
https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5

*/

Code:
----------------------------------------------------------------
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            depth+=1;
            // Node* front = q.front();
            int qSize = q.size();
            for(int  i = 0 ; i < qSize ; i++){
                Node* front = q.front();
                q.pop();
                if(front->children.size()>0)
                for(int  j = 0 ; j < front->children.size() ; j++){
                    q.push(front->children[j]);
                }
            }
            
        }
        return depth;
        
    }
};
