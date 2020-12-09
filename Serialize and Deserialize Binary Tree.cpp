/*
Problem Description : (LC 297)
---------------------------------------------------------------------------------------------------------------
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be 
stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in 
the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be 
serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not
 necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:
https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/
//Code:
//--------------------------------------------------------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
        
    }

    int helper(string& data){
        int pos = data.find(',');
        // cout<<pos<<" ";
        int val = std::stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
    TreeNode* util(string& data){
         if(data[0] == '#'){
            if(data.length()>1){
                data = data.substr(2);
            }
            return NULL;
        }
        else{
        TreeNode* root = new TreeNode(helper(data));
        root->left = util(data);
        root->right = util(data);
        
        return root;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return util(data);
       
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));