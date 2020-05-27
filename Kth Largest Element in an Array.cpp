/*
Problem Description  :(LC 215)
-----------------------------------------------------------------
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

Code:
---------------------------------------------------------------
class Solution {
public:
    int heap_size;
    vector<int> harr;
    void swap(int* a, int* b){
        int temp  = *a;
        *a = *b;
        *b = temp;
    }
    // int getMin(vectior)
    void heapify(int  i, vector<int> &nums){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;
        if(left < heap_size && nums[left]>nums[i])
            largest = left;
        if(right < heap_size && nums[right]>nums[largest])
            largest = right;
        if(largest != i){
            swap(&nums[i], &nums[largest]);
            heapify(largest, nums);
        }
    }
    void extractMax(vector<int> &arr){
        if(heap_size == 0)
            return ;
        int root = arr[0];
        if(heap_size>1){
        arr[0] = arr[heap_size-1];
        // arr.pop_back();
        heapify(0,arr);
        }
        heap_size--;
    }

    int findKthLargest(vector<int>& nums, int k) {
        // if(nums.size() == 0)
        //     return nullptr;
        heap_size = nums.size();
        for(int  j = nums.size()/2-1 ; j>=0 ; j--){
            heapify(j, nums);
        }
        for(int j = 0 ; j < k -1; j++){
            extractMax(nums);
        }
        return nums[0];
    }
};
