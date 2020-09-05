/*
Problem Description : (LC 497)
------------------------------------------------------------------------------
Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an
 integer point in the space covered by the rectangles.

Note:

An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner,
 and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]
Example 2:

Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments.
 Solution's constructor has one argument, the array of rectangles rects. pick has no arguments.
  Arguments are always wrapped with a list, even if there aren't any.
  */
 //Code:@https://www.tutorialspoint.com/random-point-in-non-overlapping-rectangles-in-cplusplus
 //---------------------------------------------------------------------------------------------------
 class Solution {
public:
    vector <int> area;
   vector < vector <int> > rect;
   int sum;
    Solution(vector<vector<int>>& rects) {
     rect = rects;
      sum = 0;
      for(int i =0 ; i < rects.size(); i++){
         int x1 = rects[i][0];
         int y1 = rects[i][1];
         int x2 = rects[i][2];
         int y2 = rects[i][3];
         int temp = (abs(x2 - x1) + 1) * (abs(y2 - y1) + 1);
         sum += temp;
         area.push_back(sum);
      }
        
    }
    
    vector<int> pick() {
        int randArea = rand() % sum + 1;
      int i;
      for(i = 0; i < area.size(); i++){
         if(randArea <= area[i]) break;
      }
      int dist_x = rand() % (abs(rect[i][0] - rect[i][2] ) + 1);
      int dist_y = rand() % (abs(rect[i][1] - rect[i][3] ) + 1);
      return {dist_x + rect[i][0], dist_y + rect[i][1]};
   
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */