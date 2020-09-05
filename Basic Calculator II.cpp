/*
Problem Description : (LC 227)
-------------------------------------------------------------------------------------------------------
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces .
 The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
//Code:
//--------------------------------------------------------------------------------------------------------------
class Solution {
public:
     int applyOp(int a, int b, char op) {
        int out = 0;
        
        switch(op){ 
            case '+': out = a + b; break;
            case '-': out = a - b; break;
            case '*': out = a * b; break;
            case '/': out = a / b; break;
        }
        return out;
    }
    
    int precedence(char op) {
        if(op == '+' || op == '-') return 1;
        else if (op == '*' || op == '/') return 2;
        else return 0;
    }
    int calculate(string s) {
           // Stack to store numbers
        stack<int> nums;
        
        // Stack to store operators
        stack<char> ops;
        
        for(int i=0; i<s.size(); ++i) {
            char ch = s[i];
            
            // If current is space, skip it
            if(ch == ' ') continue;
            
            // If current is a number
            else if(isdigit(ch)) {
                // Long type to prevent integer overflow
                long num = 0;
                
                while(i<s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                nums.push(num);
                --i;
            }
            // If current is left bracket
            else if(ch == '(') ops.push(ch);
            
            // If current is right bracket
            // Solve entire bracket
            else if(ch == ')') {
                while(!ops.empty() && ops.top() != '(') {
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();

                    int out = applyOp(num1, num2, ops.top());
                    ops.pop();
                    nums.push(out);
                }
                // Pop left bracket
                ops.pop();
                
            }
            // If current is an operator
            else {
                // While top of 'ops' has same or greater  
                // precedence to current token, which 
                // is an operator. Apply operator on top  
                // of 'ops' to top two elements in nums stack. 
                while(!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();

                    int out = applyOp(num1, num2, ops.top());
                    ops.pop();
                    nums.push(out);
                }
                ops.push(ch);
            }
        }
        
        // Entire expression has been parsed at this 
        // point, apply remaining ops to remaining 
        // values. 
        while(!ops.empty()) {
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();

            int out = applyOp(num1, num2, ops.top());
            ops.pop();
            
            nums.push(out);
        }
        
        return nums.top();;
    }
};