/*
Problem Description : (LC 605)
----------------------------------------------------------------------------------------------------
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if
n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/
//Code:
//-------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // int numOne = 0;
        // Stack.push(flowerbed[0]);
        for(int i = 0 ; i  < flowerbed.size()&&n>0 ; i++){
            if(flowerbed[i] == 1)
                continue;
            int past = i-1;
            int future = i+1;
            if((past<0 || flowerbed[past] == 0) && (future==flowerbed.size() || flowerbed[future] == 0)){
                n--;
            flowerbed[i] = 1;
            }
        }
        return n == 0;
    }
};
