/*
Problem Description : (LC 264)
----------------------------------------------------------
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/

Code:
//Approach : 1
-------------------------------------------------------------------------------------
class Solution {
public:
    
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        int ugly[n+1];
        ugly[0]=1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        int next_ugly = 1;
        for(int i = 1; i < n ; i++){//3
             ugly[i] = min(ugly[i2]*2,min(ugly[i3]*3, ugly[i5]*5));
            if(ugly[i] == ugly[i2]*2)  i2++;
            if(ugly[i] == ugly[i3]*3)  i3++;
            if(ugly[i] == ugly[i5]*5)  i5++;
        }
        return ugly[n-1];
    }
};


------------------------------------------------------------------------------------
    Approach : 2
        -----------------------------------------------------------------------------------
        //Using priority queue
        class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        priority_queue<long, vector<long>, greater<long>> pq;
        // pq.push(1);
        pq.push(2);
        pq.push(3);
        pq.push(5);
        long long val = 1;
        int count= 1;
        while(count<n){
            val = pq.top();
            pq.pop();
            cout<<val<<" ";
            if(val != pq.top()){ // to remove duplicate values
                pq.push(val*2);
                pq.push(val*3);
                pq.push(val*5);
                count++;
            }else{
                continue;
            }
        }
        return val;
        
        
    }
};
