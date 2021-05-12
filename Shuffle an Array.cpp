Problem Description : (LC 384)
-----------------------------------------------------------------------------------------------------------------------------------
  Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

1 <= nums.length <= 200
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 5 * 104 calls will be made to reset and shuffle.
  
  */
  //Code:
  //------------------------------------------------------------------------------------------------------------------------------------------------------------
  class Solution {
public:
    vector<int> org;
    Solution(vector<int>& nums) {
        org = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> suff(org);
        for(int i = 0 ; i < suff.size() ; i++){
            int pos = rand()%(suff.size()-i); //  to make sure than i+pos doesn't go outof bound 
            swap(suff[i+pos], suff[i]);
        }
        return suff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
