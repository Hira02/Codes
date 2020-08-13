/*
Problem Description : https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string/0
-----------------------------------------------------------------------------------------------------------------------
Given a string which may contains lowercase and uppercase chracters. The task is to remove all  duplicate characters from the string
 and print the resultant string.  The order of remaining characters in the output should be same as in the original string.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. 
Each test case contains a string.

Output:
Print the resultant string after removing duplicate characters from string.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
geeksforgeeks
HappyNewYear

Output:
geksfor
HapyNewYr

Explanation:
Testcase 1: After removing duplicate characters such as e, k, g, s, we have string as geksfor.
*/

//Code:
//----------------------------------------------------------------------------------------------------------------------

//#1 :
#include <bits/stdc++.h>
using namespace std;
string helper(string str){
    unordered_set<char> Set;
    int index = -1;
    for(int i = 0 ; i < str.length() ; i++){
        if(Set.find(str[i]) == Set.end()){
            Set.insert(str[i]);
            str[++index] = str[i];
        }
    }
    while(index != str.length()-1)
    str.pop_back();
    return str;
}
int main() {
	//code
	int t; // num of test case
	cin>>t;
	while(t--){
	    string str;
	    cin>> str;
	    cout<<helper(str)<<"\n";
	}
	return 0;
}
//TC : O(n)
//SC : O(n)

//#2 : https://www.geeksforgeeks.org/remove-duplicates-from-a-string-in-o1-extra-space/?ref=rp
#include <bits/stdc++.h> 
#include <string> 
using namespace std; 
  
// Function to remove duplicates 
string removeDuplicatesFromString(string str) 
{ 
  
    // keeps track of visited characters 
    int counter = 0; 
  
    int i = 0; 
    int size = str.size(); 
  
    // gets character value 
    int x; 
  
    // keeps track of length of resultant string 
    int length = 0; 
  
    while (i < size) { 
        x = str[i] - 97; 
  
        // check if Xth bit of counter is unset 
        if ((counter & (1 << x)) == 0) { 
  
            str[length] = 'a' + x; 
  
            // mark current character as visited 
            counter = counter | (1 << x); 
  
            length++; 
        } 
        i++; 
    } 
  
    return str.substr(0, length); 
} 
  
// Driver code 
int main() 
{ 
    string str = "geeksforgeeks"; 
    cout << removeDuplicatesFromString(str); 
    return 0; 
} 
//TC  : O(n)
//SC  :(1)
