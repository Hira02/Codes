/*
Problem Description : (LC 405)
--------------------------------------------------------------------------------------------------------------------------------------------------
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, 
the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
*/
//Code:
//------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string hex(int num){
        unordered_map<int, char> Map;
        char first = '0';
        char second = 'a';
        for(int i = 0 ; i< 16 ; i++){
            if(i<10)
                Map[i] = first++;
            else
                Map[i] = second++;
        }
        string res = "";
        if(num>0){
            while(num){
            res = Map[num%16]+res;
            num/=16;
        }
        }else{
            u_int n = num;
             while(n){
            res = Map[n%16]+res;
            n/=16;
        }
        }
return res;
    }
    string toHex(int num) {
        if(num == 0)
            return "0";
        return hex(num);
    }
};
