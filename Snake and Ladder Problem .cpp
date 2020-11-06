/*
Problem Description : https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0#
-------------------------------------------------------------------------------------------------------
Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination 
or last cell (30th cell) from source (1st cell) . 

Example


https://contribute.geeksforgeeks.org/wp-content/uploads/snake-and-ladders.jpg
â€‹For the above board output will be 3 
For 1st throw get a 2
For 2nd throw get a 6
For 3rd throw get a 2

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case
 contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. 
 Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which
  takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1 <= T <= 100
1 <= N <= 10
1 <= a <= 30
1 <= b <= 30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30

Output:
3
1

Explanation:
Testcase 1:
For 1st throw get a 2, which contains ladder to reach 22
For 2nd throw get a 6, which will lead to 28
Finally get a 2, to reach at the end 30. Thus 3 dice throws required to reach 30.
*/
//Code:
//---------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int minDice(vector<int> &b)
{
    //bfs starts here
    queue<pair<int, int>> pq;
    vector<bool> visited(30, false);
    pq.push(make_pair(0, 0));
    visited[0] = true;
    while (!pq.empty())
    {
        pair<int, int> cell = pq.front();
        //  cout<<cell.first<<"\n";
        if (cell.first == 29)
            return cell.second;
        pq.pop();
        for (int t = cell.first + 1; t <= cell.first + 6 && t < 30; t++)
        {
            pair<int, int> p;
            if (visited[t] == false)
            {
                visited[t] = true;
                //  cout<<t<<"\n";
                //  cell.second+=1;
                if (b[t] != -1)
                    p.first = b[t];
                else
                    p.first = t;
                p.second = cell.second + 1;
                // = make_pair(cell.first, );
                pq.push(p);
            }
        }
    }
    return -1;
}
int main()
{
    //code
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> board(30, -1);
        // for(int i = 0)
        for (int i = 0; i < n; i++)
        {
            int a;
            int b;
            cin >> a >> b;
            //cout<<a<<" "<<b<<"\n";
            board[a - 1] = b - 1;
        }
        cout << minDice(board) << "\n";
    }
    return 0;
}
/*
Priority queue will not work for the i/p : 
4
7 9 22 19 8 18 25 24

*/