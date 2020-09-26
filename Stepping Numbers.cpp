/*
Problem Description : https://www.interviewbit.com/problems/stepping-numbers/
------------------------------------------------------------------------------------------------------
Problem Description

Given A and B you have to find all stepping numbers in range A to B.

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

e.g. 123 is stepping number, but 358 is not a stepping number



Input Format
First argument is an integer A.

Second argument is an integer B.



Output Format
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



Example Input
Input 1:

 A = 10
 B = 20


Example Output
Output 1:

 [10, 12]


Example Explanation
Explanation 1:

 All stepping numbers are 10 , 12 
 */
//Code:
//--------------------------------------------------------------------------------------------------------------
void bfs(int a, int b, int num, vector<int>& res){
    queue<int> q;
    q.push(num);
    while(!q.empty()){
        int stepNum = q.front();
        q.pop();
        // cout<<stepNum<<" ";
        if(stepNum<=b && stepNum>=a)
            res.push_back(stepNum);
        if(num == 0 || stepNum>b)
            continue;
        int lastDigit = stepNum%10;
        int stepNumLeft = stepNum*10+(lastDigit-1);
        int stepNumRight = stepNum*10+(lastDigit+1);
        if(lastDigit == 0)
            q.push(stepNumRight);
        else if(lastDigit == 9)
            q.push(stepNumLeft);
        else{
            q.push(stepNumLeft);
            q.push(stepNumRight);
        }
    }
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int> res;
    for(int i = 0; i<=9 ; i++){
        bfs(A, B, i, res);
    }
    sort(res.begin(), res.end());
    return res;
}
