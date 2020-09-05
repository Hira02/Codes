/*
Problem Description : https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
------------------------------------------------------------------------------------------------------------------------------
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106

 

*/
//Code:
//-----------------------------------------------------------------------------------------------------------------------------
// Functio to find first smallest positive
// missing number in the array
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = *a;
}
int helper(int arr[], int n){
    for(int i= 0 ;i<n ; i++){
        if((abs(arr[i])-1)<=n && arr[abs(arr[i])-1]>0){
            arr[abs(arr[i])-1] = -1 * arr[abs(arr[i])-1];
        }
    }
    for(int i = 0 ; i < n ; i ++){
        if(arr[i]>0)
        return i+1;
    }
    return n+1;
}
int dividePositiveNegative(int arr[], int n){
    int i, j=0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i]<=0){
            swap(&arr[i],&arr[j++]);
        }
    }
    return j;
}
int missingNumber(int arr[], int n) { 
    
    // Your code here
    int shift = dividePositiveNegative(arr, n);
    return helper(arr+shift, n-shift);
    
} 