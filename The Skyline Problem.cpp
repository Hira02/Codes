/*
Problem Description : (Lc 218) HARD
------------------------------------------------
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance.
Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A),
write a program to output the skyline formed by these buildings collectively (Figure B).
A = https://leetcode.com/static/images/problemset/skyline1.jpg
B = https://assets.leetcode.com/static_assets/public/images/problemset/skyline2.jpg
Buildings Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. 
It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. 
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] 
that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, 
where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height.
Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. 
For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable;
the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

//first follow https://www.youtube.com/watch?v=GSBLe8cKu0s
// DO NOT USE PRIORITY_QUEUE in this problem if you are following the above way
//MULTISET is best oprion here
Code:
-----------------------------------------------------------------------------------

class Solution {
public:

    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int,int>> tempArray;
        for(int i = 0 ; i < buildings.size() ; i++){
            tempArray.emplace_back(buildings[i][0],-buildings[i][2]);
            tempArray.emplace_back(buildings[i][1], buildings[i][2]);
        }
        // automatically compares based on first and on second based on ties
       sort(tempArray.begin(),tempArray.end());
        for(auto c: tempArray){
           cout<< c.first<<" "<<c.second<<"\n";
        }
        // priority_queue<int, vector<int>, greater<int>> pq;
         // 0 for when there is no building
        multiset<int> pq{0}; 
        // pq
        int prev =0;
        int curr = 0 ;
        for(auto p:tempArray){
            if(p.second<0){ // if this is start point
                pq.insert(-p.second);
            }else{ // if this is end point
                pq.erase(pq.find(p.second));
                
            }
             // largest value in the set currently
            curr = *rbegin(pq);
            // means we have a point here
            if(prev != curr){
                res.push_back({p.first,curr});
                prev = curr;
            }
        }
        return res;
        
    }
};
//TC  : O(nlogn)
