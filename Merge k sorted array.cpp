/*
Prolem Description : 
--------------------------------------------------------------------------------
Given K sorted arrays arranged in the form of a matrix of size K*K. 
The task is to merge them into one sorted array.
Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= T <= 50
1 <= K <= 100

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9 
4
1 2 3 4 2 2 3 4 5 5 6 6 7 8 9 9

Output:
1 2 3 4 5 6 7 8 9
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 

Explanation:
Testcase 1:
Above test case has 3 sorted arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],

             [4, 5, 6],

             [7, 8, 9]]
The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Testcase 2:
Above test case has 4 sorted arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2],

             [3, 3, 4, 4],

             [5, 5, 6, 6]

             [7, 8, 9, 9 ]]
The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9 ].
*/


//Code: 
-------------------------------------------------------------------------------------------------
class triplet{
  public : 
    int element;
    int arrNum;
    int index;
    triplet(int val, int i, int j) : element(val), arrNum(i), index(j) {}
};
class myCompare{
    public : 
    bool operator() (const triplet &p1, const triplet &p2){
        return (p1.element > p2.element);
    }
};
int *mergeKArrays(int arr[][N], int k)
{
//code here
int* output = (int*)malloc(sizeof(int)*(k*k));
priority_queue<triplet , vector<triplet> , myCompare> pq;
for(int i = 0 ; i < k ; i++){
    pq.push(triplet(arr[i][0], i, 1));
}
int o_index = 0;
for(int i = 0 ; i < k*k ; i++){
    triplet top = pq.top();
    // cout<<top.element<<" ";
    pq.pop();
    output[i] = top.element;
    // triplet* newElement = new triplet();
    if(top.index<k){
        top.element = arr[top.arrNum][(top.index)];
        top.index = (top.index) +1;
        
    }else{
        top.element = INT_MAX;
        
    }
    pq.push(top);
}
return output;

}