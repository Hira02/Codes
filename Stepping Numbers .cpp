/*
Problem Description : https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output1813/1

A number is called a stepping number if all adjacent digits have an absolute difference of 1, e.g. '321' is a Stepping Number while 421 is not. 
Given two integers n and m, find the count of all the stepping numbers in the range [n, m].

Examples:

Input1 : n = 0, m = 21
Output1 : 13
Stepping no's are 0 1 2 3 4 5 6 7 8 
9 10 12 21

Input2 : n = 10, m = 15
Output2 : 2
Stepping no's are 10, 12

Your Task:  
You don't need to read input or print anything. Your task is to complete the function steppingNumbers() which takes the integer N and integer M as input 
parameters and returns the number of stepping numbers in the range between n and m.

Expected Time Complexity: O(log(M))
Expected Auxiliary Space: O(SN) where SN is the number of stepping numbers in the range


Constraints:
0 ≤ N, M ≤ 106

*/
//Code:
//--------------------------------------------------------------------------------------------------------------------------------------
class Solution{
public:
    void bfs(int n, int m, int val, int *count){
        queue<int> q;
        q.push(val);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            if(top<= m && top>= n){
                (*count)+=1;
            }
            if(top == 0 || top>m)
                continue;
            int lastDigit = top%10;
            int stepNumA = 10*top + lastDigit +1;
            int stepNumB = 10*top + lastDigit - 1;
            if(lastDigit == 0){
                q.push(stepNumA);
            }else if(lastDigit == 9){
                q.push(stepNumB);
            }else{
                q.push(stepNumA);
                q.push(stepNumB);
            }
        }
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        int count = 0;
        for(int i = 0 ; i <= 9 ; i++){
            bfs(n, m, i, &count);
        }
        return count;
    }
};
