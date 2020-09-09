/*
Problem Description : https://practice.geeksforgeeks.org/problems/remove-half-nodes/1
-----------------------------------------------------------------------------------------
Given A binary Tree. Your task is to remove all the half nodes (which has only one child).

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string 
representing the tree as described 
below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N”
denotes NULL child.

For example:
https://media.geeksforgeeks.org/wp-content/uploads/20200124141533/Untitled-Diagram65.jpg
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Single line output, print the modified tree in inorder traversal.

Your Task:
You don't need to read input or print anything. Your task is to complete the function removeHalfNodes() which takes the root node of the tree as
input and returns 
the root node of the modified tree after removing all the half nodes, ie the ones having just a single child node.
For example consider the below tree.

https://www.cdn.geeksforgeeks.org/wp-content/uploads/maxMin.png
Nodes 7, 5 and 9 are half nodes as one of their child is Null. We need to remove all such half nodes and return the root pointer of following 
new tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Binary Tree).

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
7 7 8 2
2 7 5 N 6 N 9 1 11 4
Output:
2 7 8 
1 6 11 2 4

Explanation:
Test Case 1: The given tree is:
      7
    /    \
  7      8
 /
2
The bolded 7 valued node above is the only half node in the given Binary Tree. Modified tree after removing this node is:
      7
    /    \ 
   2     8
The in-order traversal of this tree is: 2 7 8

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem,
hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/
Code:
---------------------------------------------------------------------------------------------------------------------------------------
Node *RemoveHalfNodes(Node *root)
{
   //add code here.
   if(root == NULL)
   return NULL;
   root->left = RemoveHalfNodes(root->left);
   root->right = RemoveHalfNodes(root->right);
   if(root->left == NULL && root->right == NULL)
   return root;
   if(root->left == NULL){
       return root->right;
   }
   if(root->right == NULL)
   return root->left;
   return root;
}
