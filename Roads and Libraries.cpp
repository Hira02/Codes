/*

Problem Description : (HackerRank)
--------------------------------------------------------------------
Problem Link  :https://www.hackerrank.com/challenges/torque-and-development/problem

The Ruler of HackerLand believes that every citizen of the country should have access to a library. Unfortunately, HackerLand was hit by a 
tornado that destroyed all of its libraries and obstructed its roads! As you are the greatest programmer of HackerLand, the ruler wants your
help to repair the roads and build some new libraries efficiently.

HackerLand has  cities numbered from  to . The cities are connected by  bidirectional roads. A citizen has access to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.
The following figure is a sample map of HackerLand where the dotted lines denote obstructed roads:

image
https://s3.amazonaws.com/hr-challenge-images/0/1481983010-b779ad2b2b-torque1.png
The cost of repairing any road is  dollars, and the cost to build a library in any city is  dollars. If in the above example  and , we would build  roads at a cost of  and  libraries for a cost of . We don't need to rebuild one of the roads in the cycle .

You are given  queries, where each query consists of a map of HackerLand and value of  and . For each query, find the minimum cost of
making libraries accessible to all the citizens and print it on a new line.

Function Description

Complete the function roadsAndLibraries in the editor below. It must return the minimal cost of providing libraries to all, as an integer.

roadsAndLibraries has the following parameters:

n: integer, the number of cities
c_lib: integer, the cost to build a library
c_road: integer, the cost to repair a road
cities: 2D array of integers where each  contains two integers that represent cities connected by an obstructed road .
Input Format

The first line contains a single integer , that denotes the number of queries.

The subsequent lines describe each query in the following format:
- The first line contains four space-separated integers that describe the respective values of , ,  and , the number of cities, number of roads,
cost of a library and cost of a road.
- Each of the next  lines contains two space-separated integers,  and , that describe a bidirectional road that connects cities  and .

Constraints

Each road connects two distinct cities.
Output Format

For each query, print an integer that denotes the minimum cost to make libraries accessible to all the citizens on a new line.
*/
Code:
---------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
// main execution fucntion starts here
int node;

void dfs(int val, vector<int>& visited, unordered_map<int, vector<int>>& indexing){
    node+=1;
    visited[val] = true;
    vector<int> temp = indexing[val];
    // cout<< temp.size()<<" ";
    for(int i = 0 ; i <temp.size();i++){
        if(visited[temp[i]] == false)
        dfs(temp[i], visited, indexing);
    }
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
vector<int> visited(100005,false);
unordered_map<int, vector<int>> indexing;
for(int i = 0 ; i < cities.size() ; i++){
    indexing[cities[i][0]].push_back(cities[i][1]);
    indexing[cities[i][1]].push_back(cities[i][0]);
}
long cost = 0;
for(int c = 1 ; c <= n ; c++){
    // cout<<c.first<<" ";
    if(visited[c] == false){
        node = 0;
        dfs(c, visited, indexing);
        cost = cost + c_lib;
        // cout<<node<<" \n";
        if(c_lib>c_road){
            cost = cost + (node-1)*c_road;
        }else{
            cost = cost + (node-1)*c_lib;
        }
    }
}
// node = 0;
return cost;

}
//main execution function ends here
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);


        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


