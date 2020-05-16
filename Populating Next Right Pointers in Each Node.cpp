/*
Problem Description:
--------------------------------------------
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next
right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' 
signifying the end of each level.


*/

// Code:
//---------------------------------------
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* findNext(Node* q){
    Node* temp =   q->next;
        while(temp){
            if(temp->left)
                return temp->left;
            if(temp->right)
                return temp->right;
            temp = temp->next;
        }
        return NULL;
}
    Node* connect(Node* root) {
        if(root != NULL)
            root->next = NULL;
        else
            return NULL;
        Node* p = root;
        while(p){
            Node* q = p;
            while(q){
                if(q->left){
                    if(q->right){
                        q->left->next = q->right;
                    }else{
                        q->left->next = findNext(q);
                    }
                } 
                if(q->right){
                    q->right->next = findNext(q);
                }
                q = q->next;
            }
            if(p->left)
                 p = p->left;
            else if(p->right)
                p = p->right;
            else
                p = findNext(p);
        }
        return root;
        
        
    }
};

//TC : O(n)
//SC : O(1)
