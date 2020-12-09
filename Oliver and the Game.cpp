/*
Problem Description : https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/description/
--------------------------------------------------------------------------------------------------------------------
Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. 
The people of Byteland live happily along with the King.
The city has a unique architecture with total N houses. The King's Mansion is a very big and beautiful 
bungalow having address = 1. Rest of the houses in Byteland have some unique address, (say A), are connected by roads and 
there is always a unique path between any two houses in the city. Note that the King's Mansion is also included in these houses.

Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, 
it's Oliver's turn to hide and Bob is supposed to find him.
Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver,
 he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible
  path till the last house on that path.

Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, 
then he surely finds Oliver.

Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.

The queries can be of the following two types:
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion

INPUT :
The first line of the input contains a single integer N, total number of houses in the city. Next N-1 lines contain two space 
separated integers A and B denoting a road between the houses at address A and B.
Next line contains a single integer Q denoting the number of queries.
Following Q lines contain three space separated integers representing each query as explained above.

OUTPUT :
Print "YES" or "NO" for each query depending on the answer to that query.

CONSTRAINTS :
1 ≤ N ≤ 10^5
1 ≤ A,B ≤ N
1 ≤ Q ≤ 5*10^5
1 ≤ X,Y ≤ N

NOTE :
Large Input size. Use printf scanf or other fast I/O methods.

SAMPLE INPUT 
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5
5
0 2 8
1 2 8
1 6 5
0 6 5
1 9 1
SAMPLE OUTPUT 
YES
NO
NO
NO
YES
Explanation
Query 1 Bob goes from 8 towards 1 meeting 2 in the path. Query 2 Bob goes from 8 away from 1 and never meets 2. Query 3 Bob 
goes from 5 away from 1 and never meets 6. Query 4 Bob goes from 5 towards 1 and never meets 6. Query 5 Bob goes from 1 away 
from 1 and meets finds Oliver at 9. he can take the following two paths 1 -> 2 -> 6 -> 9 OR 1 -> 2 -> 7 -> 8 9 appears in 
atleast one of them
*/
//Cde:
//------------------------------------------------------------------------------------------------------------------
/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> tree;
int vertex;
int t = 0;
vector<bool> visited;
vector<int> startTime;
vector<int> endTime;
void createTree()
{
    cin >> vertex;
    tree.resize(vertex + 1);
    for (int i = 1; i < vertex; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
    }
}
void dfs(int v)
{
    visited[v] = true;
    startTime[v] = t++;
    for (int i = 0; i < tree[v].size(); i++) // calling measureTime() for adjacent nodes of node v and performing DFS
    {
        if (visited[tree[v][i]] == 0)
            dfs(tree[v][i]);
    }
    endTime[v] = t++;
}
int check(int u, int v)
{
    if (startTime[u] > startTime[v] && endTime[u] < endTime[v])
        return 1;
    return 0;
}
int main()
{
    createTree();
    visited.resize(vertex + 1, false);
    startTime.resize(vertex + 1, 0);
    endTime.resize(vertex + 1, 0);
    dfs(1);
    int q;
    cin >> q;
    while (q--)
    {
        int dir, x, y;
        cin >> dir >> x >> y;
        // cout<<dir<<" "<<x<<" "<<y<<" "<<"\n";
        if (!check(x, y) && !check(y, x))
        {
            // cout<<"here"
            cout << "NO\n";
            continue;
        }
        // }else{
        if (dir == 0)
        {
            if (check(y, x) == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if (check(x, y) == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        // }
    }
    return 0;
}
