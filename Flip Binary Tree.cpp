/*
Problem Description : https://www.geeksforgeeks.org/flip-binary-tree/
------------------------------------------------------------------------------------------
Given a binary tree, the task is to flip the binary tree towards right direction that is clockwise.
 See below examples to see the transformation.

In the flip operation, left most node becomes the root of flipped tree and its parent become its right
 child and the right sibling become its left child and same should be done for all left most nodes recursively.
 https://media.geeksforgeeks.org/wp-content/cdn-uploads/tree13.png

 https://media.geeksforgeeks.org/wp-content/cdn-uploads/tree23.png
 */
 //Code: Geeks Solution
 //----------------------------------------------------------------------------------------------------------------
 Node* flipBinaryTree(Node* root) 
{ 
    // Base cases 
    if (root == NULL) 
        return root; 
    if (root->left == NULL && root->right == NULL) 
        return root; 
  
    //  recursively call the same method 
    Node* flippedRoot = flipBinaryTree(root->left); 
  
    //  rearranging main root Node after returning 
    // from recursive call 
    root->left->left = root->right; 
    root->left->right = root; 
    root->left = root->right = NULL; 
  
    return flippedRoot; 
}