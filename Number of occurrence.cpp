/*
Problem Description : https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1/?company[]=Amazon&problemStatus=unsolved&page=1&query=company[]AmazonproblemStatusunsolvedpage1
-----------------------------------------------------------------------------------------------------------------------------------------
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which takes the array of integers arr,
 n and x as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106
1 ≤ X ≤ 106
*/
//Code:
//---------------------------------------------------------------------------------------------------------------------
int findIndex(int arr[], int high, int x, int low, int move)
{
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            result = mid;
            if (move)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int count(int arr[], int n, int x)
{
    // code here
    int leftIndex = findIndex(arr, n - 1, x, 0, 1);

    int rightIndex = findIndex(arr, n - 1, x, 0, 0);
    if (leftIndex == -1 || arr[leftIndex] != x)
        return 0;
    // cout<<leftIndex<<" "<<rightIndex<<"\n";
    return rightIndex - leftIndex + 1;
}