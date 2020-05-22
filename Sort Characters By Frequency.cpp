/*
Problem Desription  :(Lc 451)
--------------------------------------------------
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.



*/

COde:
----------------------------------------------------
 bool sortByValue(const pair<char,int> &a,const pair<char,int> &b){
        return (a.second>b.second);
    }
class Solution {
public:
   
    string frequencySort(string s) {
        map<char,int> m;
        for(int  i = 0 ; i < s.length() ; i++){
            m[s[i]]++;
        }
        vector<pair<char,int>> v;
        map<char,int> :: iterator itr;
        for(itr = m.begin() ; itr != m.end() ; itr++){
            
            v.push_back(make_pair(itr->first,itr->second));
        }
        sort(v.begin(),v.end(),sortByValue);
        int index = 0;
        // s.clear();
        for(int i = 0 ; i<v.size();i++){
            pair<char,int> p = v[i];
            cout<<p.first<<" "<<p.second;
            while(p.second !=0){
                s[index++] = p.first;
                p.second--;
            }
        }
        
        return s;
    }
};
