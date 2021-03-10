/*
Problem Description:  (LC 12)
----------------------------------------------------------------------------------------------------------------------------------
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 
is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four
is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Example 2:

Input: num = 4
Output: "IV"
Example 3:

Input: num = 9
Output: "IX"
Example 4:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/
//Code:
//-------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    string intToRoman(int num) {
//         vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
//         vector<string> strs = {"I", "IV" , "V" , "IX", "X" , "XL" , "L", "XC" , "C" , "CD", "D", "CM","M"};
//         int i = 12;
//         string res = "";
//         while(num){
//             int mostSignificantNum = num/nums[i];
//             num = num%nums[i];
//             while(mostSignificantNum>0){
//                 res+=strs[i];
//                 mostSignificantNum--;
//             }
//             i--;
            
//         }
        string res = "";
        while(num){
            if(num>=1000){
                num-=1000;
                res+="M";
            }else if(num>=900){
                num-=900;
                res+="CM";
            }else if(num>=500){
                num-=500;
                res+="D";
            }else if(num>= 400){
                num-=400;
                res+="CD";
            }else if(num>=100){
                num-=100;
                res+="C";
            }else if(num>=90){
                num-=90;
                res+="XC";
            }else if(num>=50){
                num-=50;
                res+="L";
            }else if(num>=40){
                num-=40;
                res+="XL";
            }else if(num>=10){
                num-=10;
                res+="X";
            }else if(num>=9){
                num-=9;
                res+="IX";
            }else if(num>=5){
                num-=5;
                res+="V";
            }else if(num>=4){
                num-=4;
                res+="IV";
            }else if(num>=1){
                num-=1;
                res+="I";
            }
        }
        return res;
    }
};
