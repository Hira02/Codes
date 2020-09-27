/*
Problem Description : (LC 150)
-----------------------------------------------------------------------------------------
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there 
won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
//Code:
//--------------------------------------------------------------------------------------------------
class Solution {
public:
    bool checkForExp(string exp){
        if(exp == "+" || exp == "-" || exp == "*" || exp == "/")
            return true;
        return false;
    }
    int doCal(int a, int b, string exp){
        int result = 0;
        if(exp == "+")
                result = a+b;
         else if(exp == "-")
                result = a-b;
        else if(exp == "*")
                result = a*b;
         else
                result = a/b;
        
        return result;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> Stack;
        int i = 0 ; 
        while(i<tokens.size()){
            if(checkForExp(tokens[i])){
                int  val2 = stoi(Stack.top());
                Stack.pop();
                int val1 = stoi(Stack.top());
                Stack.pop();
                int result = doCal(val1, val2, tokens[i]);
                Stack.push(to_string(result));
            }else{
                Stack.push(tokens[i]);                
            }
            i++;
        }
        return stoi(Stack.top());
    }
};