/*
Problem Description : GFG
-----------------------------------------------------------------------------------
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8,4), (4,2),(8,2), (8,1), (4,1), (2,1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) 
*/
/*
Solution appraoch : 
https://www.geeksforgeeks.org/counting-inversions/

*/

Code:
----------------------------------------------------------------------------------------------------------------------
// C++ program to Count 
// Inversions in an array 
// using Merge Sort 
#include <bits/stdc++.h> 
using namespace std; 

int _mergeSort(int arr[],  int left, int right); 
int merge(int arr[],  int left, int mid, int right); 

/* This function sorts the input array and returns the 
number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
	//int temp[array_size]; 
	return _mergeSort(arr,  0, array_size - 1); 
} 

/* An auxiliary recursive function that sorts the input array and 
returns the number of inversions in the array. */

int _mergeSort(int arr[],int left, int right) 
{ 
	int mid; 
   int inv_count = 0;
	if (right > left) { 
		/* Divide the array into two parts and 
		call _mergeSortAndCountInv() 
		for each of the parts */
		mid = (right + left) / 2; 

		/* Inversion count will be sum of 
		inversions in left-part, right-part 
		and number of inversions in merging */
		inv_count += _mergeSort(arr,  left, mid); 
		inv_count += _mergeSort(arr,  mid + 1, right); 

		/*Merge the two parts*/
		inv_count += merge(arr, left, mid + 1, right); 
	} 
	return inv_count; 
} 

/* This funt merges two sorted arrays 
and returns inversion count in the arrays.*/
int merge(int arr[], int left, 
		int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			//temp[k++] = arr[i++]; 
          i++;
          continue;
		} 
		else { 
			//temp[k++] = arr[j++]; 

			/* this is tricky -- see above 
			explanation/diagram for merge()*/
          j++;
			inv_count = inv_count + (mid - i); 
		} 
	} 



	return inv_count; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {3,1,2}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int ans = mergeSort(arr, n); 
	cout << " Number of inversions are " << ans; 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
