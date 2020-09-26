/*
Problem Description : (LC : 1286)
------------------------------------------------------------------------------------
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
*/

//Code:
//-----------------------------------------------------------------------------------------
class CombinationIterator {
    vector<string> arr;
    int idx;
public:
    void create(string s, int l, string res = "", int start = 0){
        if(res.size() == l){
            arr.push_back(res);
            return ;
        }
        for(int i = start ; i<s.length()  ; i++){
            create(s, l, res+s[i], i+1);
        }
    }
    CombinationIterator(string s, int l) {
        create(s, l);
        idx = 0;
    }
    
    string next() {
         ++idx;
        return arr[idx-1];
        
       
    }
    
    bool hasNext() {
       return !(idx == arr.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */