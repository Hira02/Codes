/*
Problem Desscription : (LC 76) HARD
--------------------------------------------------------------
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

//Code:
//-------------------------------------------------------------------------------------
class Solution {
public:
   string minWindow(string S, string T) {
    string result;
    if(S.empty() || T.empty()){
        return result;
    }
    unordered_map<char, int> map;
    unordered_map<char, int> window;
    for(int i = 0; i < T.length(); i++){
        map[T[i]]++;
    }
    int minLength = INT_MAX;
    int letterCounter = 0;
    for(int slow = 0, fast = 0; fast < S.length(); fast++){
        char c = S[fast];
        if(map.find(c) != map.end()){
            window[c]++;
            if(window[c] <= map[c]){
                letterCounter++;
            }
        }
        if(letterCounter >= T.length()){
            while(map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]]){
                window[S[slow]]--;
                slow++;
            }
            if(fast - slow + 1 < minLength){
                minLength = fast - slow + 1;
                result = S.substr(slow, minLength);
            }
        }
    }
    return result;
}
};

#java

class Solution {
    public String minWindow(String p, String t) {
        int len1 = p.length();
        int len2 = t.length();
        if(len1<len2)
            return "";
        int hash_t[] = new int[256];
        int hash_p[] = new int[256];
        // Arrays.fill(hash_t, 0);
        // Arrays.fill(hash_p, 0);
        // int count_t = 0;
        for(int i = 0 ; i< len2 ; i++){
            hash_t[t.charAt(i)-0]++;
        }
        
        int start = 0, start_ind = -1;
        int maxLen = Integer.MAX_VALUE;
        int count = 0;
        for(int i = 0 ; i < len1;  i++){
            hash_p[p.charAt(i)-0]++;
            if(hash_p[p.charAt(i)-0] <= hash_t[p.charAt(i)-0])
                count++;
                if(count == len2){
                    while(hash_p[p.charAt(start)-0]>hash_t[p.charAt(start)-0] || hash_t[p.charAt(start)-0] == 0){
                        if(hash_p[p.charAt(start)-0]>hash_t[p.charAt(start)-0]){
                            hash_p[p.charAt(start)-0]--;
                        }
                        start++;                        
                    }
                    int currWindow = i-start+1;
                if(maxLen>currWindow){
                    maxLen = currWindow;
                    start_ind = start;
                }
                }
                
            
        }
        if(maxLen == Integer.MAX_VALUE)
            return "";
        return p.substring(start_ind, start_ind+maxLen);
        
    }
}