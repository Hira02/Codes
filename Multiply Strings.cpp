/*
Problem Description : (LC 43)
---------------------------------------------------------------------------------
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2,
 also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
//Code:
//-------------------------------------------------------------------------------------------------
class Solution {
public:
    string multiply(string num1, string num2) {
            //standared multiplication rule
        int n = num1.size();
        int m = num2.size();
        string ans(n+m,'0');
        for(int i = n-1; i >=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                int sum = (ans[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0');
                 ans[i+j+1] = sum%10 + '0';
                ans[i+j] += (sum/10);
            }
        }
        for(int i = 0 ; i < n+m ; i++){
            if(ans[i] != '0')
                return ans.substr(i);
        }
        return "0";
    }
};