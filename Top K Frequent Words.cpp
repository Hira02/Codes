/*

Problem Description : (LC 692)
---------------------------------------------
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/
Code:
-----------------------------------------------------------------------
class counter{
  public : 
    string s;
    int countValue;
    counter(string str, int countVal){
        s = str;
        countValue = countVal;
    }
};
class myComp{
  public : 
    bool operator()(const counter &a, const counter &b){
        if(a.countValue ==  b.countValue){
            if(a.s>b.s)
                return true;
            return false;
        }
        return a.countValue<b.countValue;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;
        for(int  i = 0 ; i < words.size() ; i++){
            m[words[i]]++;
        }
        priority_queue<counter, vector<counter>, myComp> pq;
        for(auto c : m){
            pq.push(counter(c.first, c.second));
        }
        for(int  i = 0 ; i < k ; i++){
            counter str = pq.top();
            pq.pop();
            res.push_back(str.s);
        }
        return res;
    }
};
