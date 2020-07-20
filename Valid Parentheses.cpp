/*
Problem Description : (LC 20)
---------------------------------------------------------------------
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/


COde:
--------------------------------------------------------------------------------------
class Solution {
public:
    bool isValid(string str) {
        if(str.length()%2 !=0){
	       return false;
	    }
         stack<char> Stack;
	        for(int i = 0 ; i < str.length() ; i++){
	            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
	                Stack.push(str[i]);
	            }else{
	                if(Stack.size()>0){
	                    char top = Stack.top();
	                    Stack.pop();
	                    if(str[i] == ')'){
	                        if(top != '(')
	                        return false;
	                    }else if(str[i] == '}'){
	                        if(top != '{')
	                        return false;
	                        
	                    }else if(str[i] == ']'){
	                        if(top != '[')
	                        return false;
	                    }
	                
	                }else{
	                    return false;
	                }
	            }
	        }
       return (Stack.size()>0)? false:  true;
	            // return true;
    }
};
