/*
Problem Description : https://practice.geeksforgeeks.org/problems/josephus-problem/1/?company[]=Microsoft&company[]=Microsoft&problemStatus=unsolved&problemType=functional&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&page=1&sortBy=submissions&query=company[]MicrosoftproblemStatusunsolvedproblemTypefunctionaldifficulty[]-2difficulty[]-1difficulty[]0page1sortBysubmissionscompany[]Microsoft#
------------------------------------------------------------------------------------------------------------------------------------------------
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Example 1:

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.
 

Example 2:

Input:
n = 5 k = 3
Output: 4
Explanation: There are 5 persons so 
skipping 2 person i.e 3rd person will 
be killed. Thus the safe position is 4.
 

Your Task:
You don't need to read input or print anything. You are required to complete the function josephus () that takes two parameters n and k and returns an integer 
denoting safe position. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= k, n <= 20
*/
//Code:
//----------------------------------------------------------------------------------------------------------------------------------
 int josephus(int n, int k)
{
    vector<int> List;
    for(int i = 1;i<= n ; i++)
        List.push_back(i);
    return helper( k-1, 0, List);
   //Your code here
}
int helper(int k, int start, vector<int>& list){
    if(list.size() == 1)
        return list[0];
    start = (start+k)%list.size();
    list.erase(list.begin()+start);
    return helper(k, start, list);
}
