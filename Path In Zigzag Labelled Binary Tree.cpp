/*
Problem Description:(LC 1104)
-----------------------------------------
In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, 
while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
quiestion link :(https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)

Solution approach link : https://medium.com/algorithm-and-datastructure/path-in-zigzag-labelled-binary-tree-a2e9e7cc7eb1
Thanks to medium.com for this wonderful explanation :)

 

*/
Code:
-------------------------------------------------
class Solution {
public:
    int getCurrLevel(int label){
        int n = 1;
        while(pow(2,n)<=label){
            n++;
        }
        return n;
    }
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        while(label>1){
            res.push_back(label);
            int currLevel = getCurrLevel(label);
            if(currLevel %2 ==0){
                int distance = label - pow(2,currLevel-1);
                int preLevel = currLevel-1;
                int preLevelStart = pow(2,preLevel)-1;
                int next = preLevelStart-distance/2;
                label = next;
            }else{
                int distance = pow(2,currLevel)-1-label;
                int preLevel = currLevel-1;
                int preLevelStart = pow(2,preLevel-1);
                int next = preLevelStart+distance/2;
                label = next;
            }
        }
        res.push_back(label);
        reverse(res.begin(), res.end());
        return res;
    }
};
