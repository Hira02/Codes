/*
Problem Description : (LC 421)
----------------------------------------------------------------------------
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/
//Code:
//--------------------------------------------------------------------------------------
class Node{
  public : 
    Node* one_node;
    Node* zero_node;
    Node(): one_node(NULL), zero_node(NULL){}
    // ~Node();
    void insert(int num, Node* root){
        Node* currNode = root;
        for(int i = 31 ; i>=0 ; i--){
            int bitValue = (num>>i)/*moving right by i no of bits*/ & 1;
            if(bitValue){
                if(currNode->one_node == NULL){
                    currNode->one_node = new Node();
                }
                   currNode =  currNode->one_node;
                
            }else{
                if(currNode->zero_node == NULL){
                    currNode->zero_node = new Node();
                }
                   currNode =  currNode->zero_node;
                
            }
        }
    }
    int getCurrXOR(int num, Node* root){
        int res = 0;
        Node* curr = root;
        for(int i = 31 ; i>=0 ; i--){
            int currBit = (num>>i) & 1;
            if(currBit){// if current bit 1 then we should be searching for 0 to make XOR maximum
                if(curr->zero_node){
                    res += pow(2, i);// res = res | (1<<i)
                    curr = curr->zero_node;
                }else{
                    curr = curr->one_node;
                }
            }else{
                if(curr->one_node){
                    res += pow(2, i);
                    curr = curr->one_node;
                }else{
                    curr = curr->zero_node;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        int res = 0;
        for(auto t : nums){
            root->insert(t, root);
        }
        for(auto t : nums){
            int currXORvalue = root->getCurrXOR(t, root);
            // cout<<currXORvalue<<"\n";
            res = max(res, currXORvalue);
        }
        delete(root);
        return res;
    }
};