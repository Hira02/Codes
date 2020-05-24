/*
Problem Description: (LC 1456)
-----------------------------------------------
Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.
Example 5:

Input: s = "tryhard", k = 4
Output: 1


*/
Code:
-------------------------------------------
class Solution {
public:
    int maxVowels(string s, int k) {
        int max_ = 0;
         int count = 0;
        int j = 0;
        for(j = 0 ; j <k; j++){
           
            // for(int j = i;j<i+k ; j++){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'u' || s[j] == 'i'){
                    count++;
                }
            max_ = max(max_,count);
            }
        for(;j<s.length() ;j++){
             // if(count>max_)
             //    max_ = count;
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'u' || s[j] == 'i'){
                    count++;
                }
            if(s[j-k] == 'a' || s[j-k] == 'e' || s[j-k] == 'o' || s[j-k] == 'u' || s[j-k] == 'i'){
                    count--;
                }
             if(count>max_)
                max_ = count;
           
        }
            
            
        
        return max_;
    }
};
