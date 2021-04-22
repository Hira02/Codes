/*
Problem Description : (https://practice.geeksforgeeks.org/problems/sum-tree/1/?company[]=Microsoft&company[]=Microsoft&problemStatus=unsolved&problemType=functional&difficulty[]=1&page=1&sortBy=submissions&query=company[]MicrosoftproblemStatusunsolvedproblemTypefunctionaldifficulty[]1page1sortBysubmissionscompany[]Microsoft#)
-----------------------------------------------------------------------------------------------------------------------------------------------------
Given a Binary Tree. Check whether it is a Sum Tree or not.

A Binary Tree is a Sum Tree in which value of each node x is equal to sum of nodes present in its left subtree and right subtree . 
An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. A leaf node is also considered as a Sum Tree.

Example 1:

Input:
    3
  /   \    
 1     2

Output: 1
Explanation: The given tree is a sum 
tree so return a boolean true.

Example 2:

Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum
tree. For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.

Your Task: 
You dont need to read input or print anything. Complete the function isSumTree() which takes root node as input parameter and returns tru
e if the tree is a SumTree else it returns false.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the Tree)

*/
//Code:
//---------------------------------------------------------------------------------------------------------------------------------
class Solution
{
    public:
    bool isLeaf(Node* root){
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right== NULL)
            return true;
        return false;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root == NULL || isLeaf(root)){
             return 1;
         }
         if(isSumTree(root->left) && isSumTree(root->right)){
             int ls = 0, rs= 0;
             if(root->left == NULL)
                ls = 0;
             else if(isLeaf(root->left)){
                 ls = root->left->data;
             }else{
                 ls = 2* root->left->data;
             }
             if(root->right == NULL)
                rs = 0;
             else if(isLeaf(root->right)){
                 rs = root->right->data;
             }else{
                 rs = 2* root->right->data;
             }
             return root->data == ls+rs;
         }
         return 0;
    }
};
