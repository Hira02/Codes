/*
Problem Description : (HackerRank)
--------------------------------------------------------
https://www.hackerrank.com/challenges/bfsshortreach/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=7-day-campaign

*/
Code:
-------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// main code starts
// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    unordered_map<int, vector<int>> indexing;
    for(int i = 0 ; i < edges.size() ; i++){
        indexing[edges[i][0]].push_back(edges[i][1]);
        indexing[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> distance(n+1,-1);
    queue<int> q;
    q.push(s);
    distance[s] = 0;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        // cout<<indexing[top].size()<<" ";
        vector<int> temp = indexing[top];
        // sort(temp.begin(),temp.end());
        for(int i = 0 ;i< temp.size() ; i++){
            if(distance[temp[i]] == -1){
                q.push(temp[i]);
                distance[temp[i]] = distance[top]+6;
            }
        }
    }
    vector<int> ans;
    for(int i= 1; i<distance.size();i++){
        if(distance[i] != 0)
        ans.push_back(distance[i]);
    }
    return ans;
    // while()

}
//main code ends
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
