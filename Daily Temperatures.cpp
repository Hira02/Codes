/*
Problem Description : (LC 739)
------------------------------------------------------------------------------------------------------
Given a list of daily temperatures T, return a list such that, for each day in the input,
 tells you how many days you would have to wait until a warmer temperature. If there is no future
  day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], 
your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. 
Each temperature will be an integer in the range [30, 100].
*/
//Code:
//--------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> Stack;
        vector<int> result(T.size() , 0);
        for(int i = 0 ; i < T.size() ; i++){
            if(Stack.empty() || T[Stack.top()]>=T[i]){
                Stack.push(i);
            }else{
                while(!Stack.empty() && T[Stack.top()]<T[i]){
                    int top = Stack.top();
                    Stack.pop();
                    result[top] = (i-top);
                }
                Stack.push(i);
            }
        }
        return result;
    }
};