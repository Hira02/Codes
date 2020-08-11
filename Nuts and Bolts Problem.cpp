/*
Problem Description : GFG
------------------------------------------------------------------------------------------------------------
Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts.
 Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt
 can only be compared with nut to see which one is bigger/smaller.

Input:
The first line contains 'T' denoting the number of testcases. Then follows description of T testcases:
Each case begins with a single positive integer N denoting the number of nuts/bolts. Then follows the array of nuts, each element
 separated by a space. And finally the bolts array, again, each element is separated by a space here. Array of Nuts/Bolts can only 
 consist of the following elements:{'@', '#', '$', '%', '^', '&', '~', '*', '!'}. And no element can be repeated.

Output:
For each test case, output the matched array of nuts and bolts in separate lines, where each element in the array is separated by a space.
Print the elements in the following order ! # $ % & * @ ^ ~ 

Constraints:
1 <= T <= 70
1 <= N <= 9

Example:
Input:
2
5
@ % $ # ^
% @ # $ ^
9
^ & % @ # * $ ~ !
~ # @ % & * $ ^ ! 

Output:
# $ % @ ^
# $ % @ ^
! # $ % & * @ ^ ~
! # $ % & * @ ^ ~

 */
//Code:
//--------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void swap(char* a, char* b){
  
 char temp = *a;
  *a = *b;
  *b = temp;
}
int partition(char arr[], int low, int high, char pivot){
    int i = low - 1;
    for(int j = low;  j<high ; j++){
        if(arr[j]< pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }else if(arr[j] == pivot){
            swap(&arr[j], &arr[high]);
            j--;
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return i;
}
void quickSort(char nuts[], char bolts[],int low,  int high){
    if(low<high){
    int pivot = partition(nuts, low, high, bolts[high]);
    partition(bolts, low, high, nuts[pivot]);
    quickSort(nuts, bolts, low, pivot-1);
    quickSort(nuts, bolts, pivot+1, high);
}
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    char nuts[n];
	    char bolts[n];
	    for(int i = 0 ; i < n ; i ++){
	        cin>>nuts[i];
	    }
	    for(int i = 0 ; i < n ; i ++){
	        cin>>bolts[i];
	    }
	    quickSort(nuts, bolts,0, n-1);
	    for(int i = 0 ; i < n ; i ++){
	        cout<<nuts[i]<<" ";
	    }
	    cout<<"\n";
	    for(int i = 0 ; i < n ; i ++){
	        cout<<bolts[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}