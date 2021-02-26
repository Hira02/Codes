/*
Problem Description : (LC 946)
---------------------------------------------------------------------------------------------------------------
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop
operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
*/
//Code:
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
#1: Without using extra space

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     int len = pushed.size();
        int idx = -1;
        int j = 0;
        for(int i = 0 ; i < len ; i++){
            pushed[++idx] = pushed[i];
            while(idx>=0 && pushed[idx] == popped[j]){
                j++;
                idx--;
            }
        }
        return j == popped.size();
    }
};

#2: Using Stack

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        stack<int> Stack;
        int j  = 0;
        for(int i  = 0 ; i < len ; i++){
            Stack.push(pushed[i]);
            while(!Stack.empty() && j<len && Stack.top() == popped[j]){
                Stack.pop();
                j++;
            }
        }
        return Stack.empty() == true;
        
    }
};
