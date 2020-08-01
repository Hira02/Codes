/*
Problem Description : (LC 520)
--------------------------------------------------------------------------
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

Code:
--------------------------------------------------------------------------------------------------
class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.length();
        int count=  0;
        bool first = false;
        for(int i = 0 ; i < len ; i++){
            int asciiValue = (int)word[i];
            cout<<asciiValue<<" ";
            if(i == 0)
                if(asciiValue>=65 && asciiValue<=90)
                    first = true;
            if(asciiValue >= 65 && asciiValue<=90)
                count++;
        }
        if(count == 0 ||(count == 1 && first == true))
            return true;
        return (count == len);
    }
};
