/*
Problem Description : GFG
--------------------------------------------------------------------------------------------------
Consider a big party where a log register for guest’s entry and exit times is maintained. Find the time at which there are maximum
 guests at the party. Note that entries in the register are not in any order.  if two events have the same time, 
 then arrival is preferred over the exit.



Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains an integer n denoting the size of the entry and exit array. Then the next two lines contains 
the entry and exit array respectively.

Output:
Print the maximum no of guests and the time at which there are maximum guests at the party.

Constraints:
1<=T<=10^5
1<=N<=10^5
1<=entry[i],exit[i]<=10^5

Example:
Input:
2
5
1 2 10 5 5
4 5 12 9 12
7
13 28 29 14 40 17 3 
107 95 111 105 70 127 74 

Output:
3 5
7 40

*/
//Code:
//---------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void helper(int arrive[], int depart[], int n){
    int maxCount = 1;
    int currCount = 1;
    int maxTime = arrive[0];
    sort(arrive, arrive+n);
    sort(depart, depart+n);
    int i = 1,  j =0;
    while(i<n && j<n){
        if(arrive[i]<=depart[j]){
            currCount++;
           
            if(currCount>maxCount){
                maxCount = currCount;
                maxTime = arrive[i];
            }
             i++;
        }else{
            currCount--;
            j++;
        }
    }
    cout<<maxCount<<" "<<maxTime;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arrive[n];
	    int depart[n];
	    for(int i = 0 ; i < n ; i++){
	        cin>>arrive[i];
	    }
	     for(int i = 0 ; i < n ; i++){
	        cin>>depart[i];
	    }
	    helper(arrive, depart, n);
	    cout<<"\n";
	}
	return 0;
}