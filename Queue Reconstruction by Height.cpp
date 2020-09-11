/*
Problem Description : (LC 406)
-----------------------------------------------------------------
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is 
the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
Code:
--------------------------------------------------------------------
class Solution {
public:
     static bool myComp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort the input array based non-decreasing heights, if two height is same then then sort by
        //non-increasing value of k
        sort(people.begin(),people.end(),myComp);
        //array will look like this:
        //input : [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
        //output: [[4,4],[5,2],[5,0],[6,1],[7,1],[7,0]]
        vector<vector<int>> ans(people.size(),vector<int>());//blank array same as inout array
        for(int  i = 0 ; i < people.size() ; i++){
            int count=0;// will count number of blank space
            int j;
            for(j = 0 ; j < ans.size() ; j++){
                if(ans[j].size() ==0){
                    if(count == people[i][1]){
                        break;
                    }
                    count++;
                }
            }
            ans[j] = people[i];
/*
            ans array is getting filled by below way
step1: [[  ,  ], [  ,  ], [  ,  ], [  ,  ], [4,4], [  ,  ]]
step2: [[  ,  ], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
step3: [[5,0], [  ,  ], [5,2], [  ,  ], [4,4], [  ,  ]]
step4: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [  ,  ]]
step5: [[5,0], [  ,  ], [5,2], [6,1], [4,4], [7,1]]
step6: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
            cout<<ans[j][0]<<"\n";
        }
        return ans;
    }
};
