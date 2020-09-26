/*
Problem Description:(LC 1452)
----------------------------------
Given the array favoriteCompanies where favoriteCompanies[i] is the list of favorites companies for the ith person (indexed from 0).

Return the indices of people whose list of favorite companies is not a subset of any other list of favorites companies.
You must return the indices in increasing order.

 

Example 1:

Input: favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
Output: [0,1,4] 
Explanation: 
Person with index=2 has favoriteCompanies[2]=["google","facebook"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"]
corresponding to the person with index 0. 
Person with index=3 has favoriteCompanies[3]=["google"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] 
and favoriteCompanies[1]=["google","microsoft"]. 
Other lists of favorite companies are not a subset of another list, therefore, the answer is [0,1,4].
Example 2:

Input: favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
Output: [0,1] 
Explanation: In this case favoriteCompanies[2]=["facebook","google"] is a subset of favoriteCompanies[0]=["leetcode","google","facebook"],
therefore, the answer is [0,1].
Example 3:

Input: favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
Output: [0,1,2,3]
 

Constraints:

1 <= favoriteCompanies.length <= 100
1 <= favoriteCompanies[i].length <= 500
1 <= favoriteCompanies[i][j].length <= 20
All strings in favoriteCompanies[i] are distinct.
All lists of favorite companies are distinct, that is, If we sort alphabetically each list then favoriteCompanies[i] != favoriteCompanies[j].
All strings consist of lowercase English letters only.
*/


Code:
-------------------------------------------
class Solution {
public:
    bool isSubSet(int a, int b, vector<vector<string>>& favoriteCompanies){
        int n = favoriteCompanies[a].size();
        int m  = favoriteCompanies[b].size();
        if(n>m)
            return false;
        int j = 0 ;
        // int count = 0;
        
        /*
        example 1:
        a = ["facebook","google"] after sorting n = 2
        b = [facebook","google","leetcode"] after sorting m = 3
        
        example 2:
        a = ["abc","google"]
        b = ["facebook","google","leetcode"]
        in this case j increments to m and thus j<m becomes false and f value stays 0 thus return false as a can't be a subset of b
        
        */
        for(int  i = 0 ; i < n ; i++){
            int f = 0;
            while(j<m && favoriteCompanies[a][i] != favoriteCompanies[b][j]){
                j++;
            }
            if(j<m) f = 1;
            if(!f) return false;
        }
        return true;
       
    }
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int size = favoriteCompanies.size();
        for(int  i = 0 ; i < size ; i ++){
            sort(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        }
        vector<int> res;
        for(int  i = 0 ; i < size ; i++){
             int f= 1;
            for(int j = 0 ; j < size ; j++){
                if(i == j)
                    continue;
               
                if(isSubSet(i, j, favoriteCompanies)){// check whether j is a subset of i or not, if yes then don't add else add
                    f = 0;
                    break;
                }              
                    
            }
             if(f == 1) res.push_back(i);
        }
        return res;
        
    }
};
