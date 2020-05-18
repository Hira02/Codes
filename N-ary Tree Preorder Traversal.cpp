/*
Problem Description:
------------------------------------------
Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal,
each group of children is separated by the null value (See examples). 

Follow up:

Recursive solution is trivial, could you do it iteratively?
Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

*/
Code:
--------------------------------------------------
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node* > s;
        s.push(root);
        while(!s.empty()){
            Node* temp = s.top();
            res.push_back(temp->val);
            s.pop();
            for(int i=temp->children.size()-1 ; i>=0 ; i--){
                cout<<temp->children[i]->val<<"\n";
                if(temp->children[i]){
                    s.push(temp->children[i]);
                }
            }
        }
        return res;
        
    }
};
TC : O(n)
SC  :O(n)
