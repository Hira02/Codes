/*
Problem Description: (LC 60)
--------------------------------------------------------------------------
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"

*/

Code:
-----------------------------------------------------------------------------
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[n+1];
        int sum = 1;
        fact[0] = 1;
        for(int i=1; i<=n; i++){
         sum *= i;
         fact[i] = sum;
     }
        vector<int> numbers;
        for(int i = 1 ; i<=n ; i++){
            numbers.push_back(i);
        }
        k--;
        string ans = "";
        for(int i = 1; i <= n; i ++){
            int index = k/fact[n-i];
            ans+=(numbers[index]+'0');
            vector<int>::iterator it= numbers.begin()+index;
            numbers.erase(it);
            k = k - (index)*fact[n-i];
        }
        return ans;
        
    }
};

//Thanks to https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n)
// for the greate explanation
