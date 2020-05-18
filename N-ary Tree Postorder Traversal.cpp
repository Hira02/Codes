/*
Problem Description:(LC 590)
-----------------------------------
Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children 
is separated by the null value (See examples).

Follow up:

Recursive solution is trivial, could you do it iteratively?

https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png
Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
*/
Code:
-------------------------------------------------------------
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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> s1;// children
        stack<Node*> s2;// parents
        s1.push(root);
        while(!s1.empty()){
            Node* top = s1.top();
            s1.pop();
            s2.push(top);
            int childrenSize = top->children.size();
            for(int  i = 0 ; i < childrenSize ; i++){
                s1.push(top->children[i]);
            }
        }
        while(!s2.empty()){
            Node* top = s2.top();
            res.push_back(top->val);
            s2.pop();
        }
        return res;
        
    }
};
