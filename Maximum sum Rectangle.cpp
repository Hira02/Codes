#include <bits/stdc++.h>
using namespace std;
class Result
{
public:
    int maxSum = 0;
    int leftBound;
    int rightBound;
    int upBound;
    int lowBound;
};
class KadaneResult
{
public:
    int maxSum;
    int start;
    int end;
    KadaneResult(int maxSum, int start, int end)
    {
        this->maxSum = maxSum;
        this->start = start;
        this->end = end;
    }
};
KadaneResult *kadane(vector<int> &arr)
{
    int max_ = 0;
    int maxStart = -1;
    int maxEnd = -1;
    int currentStart = 0;
    int maxSoFar = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxSoFar += arr[i];
        if (maxSoFar < 0)
        {
            maxSoFar = 0;
            currentStart = i + 1;
        }
        if (max_ < maxSoFar)
        {
            maxStart = currentStart;
            maxEnd = i;
            max_ = maxSoFar;
        }
    }
    cout<<max_<<" ";
    KadaneResult *newResult = new KadaneResult(max_, maxStart, maxEnd);
    return newResult;
}
int maxRect(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> temp(n);
    Result *result = new Result();
    for (int left = 0; left < m; left++)
    {
        for (int i = 0; i < n; i++)
        {
            temp[i] = 0;
        }
        for (int right = left; right < m; right++)
        {
            for (int i = 0; i < n; i++)
            {
                temp[i] += mat[i][right];
            }
            KadaneResult *kadaneResult = kadane(temp);
            // cout<<kadaneResult->maxSum<<" ";
            if (kadaneResult->maxSum > result->maxSum)
            {
                result->maxSum = kadaneResult->maxSum;
                result->leftBound = left;
                result->rightBound = right;
                result->upBound = kadaneResult->start;
                result->lowBound = kadaneResult->end;
            }
        }
    }
    return result->maxSum;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat;
        for (int i = 0; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j < m; j++)
            {
                int val;
                cin >> val;
                row.push_back(val);
            }
            mat.push_back(row);
        }
        cout << maxRect(mat) << "\n";
    }

    return 0;
}