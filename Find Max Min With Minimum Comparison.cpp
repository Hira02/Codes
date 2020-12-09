/*
Problem Description : https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
--------------------------------------------------------------------------------------------------------------------------
Given a list of numbers of size n, where n is greater than 3, find the maximum and minimum of the list using less than 
2 * (n - 1) comparisons.

*/

//Code: GFG solution
//-------------------------------------------------------------------------------------------------------------------
// C++ program of above implementation 
#include<iostream> 
using namespace std; 

// Structure is used to return 
// two values from minMax() 
struct Pair 
{ 
	int min; 
	int max; 
}; 

struct Pair getMinMax(int arr[], int n) 
{ 
	struct Pair minmax;	 
	int i; 
	
	// If array has even number of elements 
	// then initialize the first two elements 
	// as minimum and maximum 
	if (n % 2 == 0) 
	{ 
		if (arr[0] > arr[1])	 
		{ 
			minmax.max = arr[0]; 
			minmax.min = arr[1]; 
		} 
		else
		{ 
			minmax.min = arr[0]; 
			minmax.max = arr[1]; 
		} 
		
		// Set the starting index for loop 
		i = 2; 
	} 
	
	// If array has odd number of elements 
	// then initialize the first element as 
	// minimum and maximum 
	else
	{ 
		minmax.min = arr[0]; 
		minmax.max = arr[0]; 
		
		// Set the starting index for loop 
		i = 1; 
	} 
	
	// In the while loop, pick elements in 
	// pair and compare the pair with max 
	// and min so far 
	while (i < n - 1) 
	{		 
		if (arr[i] > arr[i + 1])		 
		{ 
			if(arr[i] > minmax.max)	 
				minmax.max = arr[i]; 
				
			if(arr[i + 1] < minmax.min)		 
				minmax.min = arr[i + 1];	 
		} 
		else	
		{ 
			if (arr[i + 1] > minmax.max)	 
				minmax.max = arr[i + 1]; 
				
			if (arr[i] < minmax.min)		 
				minmax.min = arr[i];	 
		} 
		
		// Increment the index by 2 as 
		// two elements are processed in loop 
		i += 2; 
	}		 
	return minmax; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1000, 11, 445, 
				1, 330, 3000 }; 
	int arr_size = 6; 
	
	Pair minmax = getMinMax(arr, arr_size); 
	
	cout << "nMinimum element is "
		<< minmax.min << endl; 
	cout << "nMaximum element is "
		<< minmax.max; 
		
	return 0; 
} 
/*
Proof  :
 If n is odd:    3*(n-1)/2  
 If n is even:   1 Initial comparison for initializing min and max, 
 and 3(n-2)/2 comparisons for rest of the elements  =  1 + 3*(n-2)/2 = 3n/2 -2
*/
