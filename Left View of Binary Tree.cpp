/*
Problem Description : https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/?company[]=Amazon&company[]=Amazon&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissionscompany[]Amazon#
-----------------------------------------------------------------------------------------------------------------------------------------
view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/
//Code:
//--------------------------------------------------------------------------------------------------------------------------------------
 void helper(Node* root, int level, vector<int>& Map){
     if(root == NULL)
        return ;
    if(Map.size()<level)
        Map.push_back(root->data);
    helper(root->left, level+1, Map);
    helper(root->right, level+1, Map);
 }

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   vector<int> storage;
   helper(root, 1, storage);
//   for(auto t: storage){
//       res.push_back(t);
//   }
   return storage;
}
