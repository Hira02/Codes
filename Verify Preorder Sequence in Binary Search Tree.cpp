Problem description  :
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.
Input: preorder = [1,3,2]
Output: true



CODE:
---------------

class Solution {
public:
    /**
     * @param preorder: List[int]
     * @return: return a boolean
     */
    bool verifyPreorder(vector<int> &preorder) {
        int low = INT_MIN, i = -1;
        for(auto p: preorder){
            if(low>p)
            return false;
            while(i>=0 && p>preorder[i])
            low = preorder[i--];
            preorder[++i] = p;
        }
        return true;
    }
};
