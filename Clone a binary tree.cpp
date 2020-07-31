/*
Problem Description : 
-----------------------------------------------------------------------------
Given a Binary Tree having random pointers clone the Binary Tree. The task is to complete the function cloneTree which take one argument the root of the tree to
be copied and should return the root of the cloned tree.


Code:
-----------------------------------------------------------------------------------

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

/* The function should clone the passed tree and return 
   root of the cloned tree */
   void clonerRandom(Node* tree, Node* cloneTree,  unordered_map<Node*, Node*>& Map){
       if(tree == NULL)
       return ;
       cloneTree->random = Map[tree->random];
       clonerRandom(tree->left, cloneTree->left, Map);
       clonerRandom(tree->right, cloneTree->right, Map);
   }
   Node* copyLeftRight(Node* tree, unordered_map<Node*, Node*>& Map){
       if(tree == NULL)
       return NULL;
       Node* cloneTree = new Node(tree->data);
       Map[tree] = cloneTree;
       cloneTree->left = copyLeftRight(tree->left, Map);
       cloneTree->right = copyLeftRight(tree->right, Map);
       return cloneTree;
   }
   
Node* cloneTree(Node* tree)
{
    if(tree == NULL)
    return NULL;
    unordered_map<Node*, Node*> Map;
   Node* newTree =  copyLeftRight(tree, Map);
   clonerRandom(tree, newTree, Map);
   return newTree;
   //Your code here
}
