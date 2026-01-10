#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int n = grid.size();
        int m = grid[0].size();

        int rem = grid[0][0] % x;

        vector<int> remVec;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] % x != rem)
                    return -1;
                else
                    remVec.push_back(grid[i][j]);
            }
        }

        sort(remVec.begin(), remVec.end());

        int sz = m * n;
        int idx = sz / 2;
        int median = remVec[idx];

        int result = 0;

        for (int i = 0; i < sz; i++)
        {
            if (median != remVec[i])
                result += abs(remVec[i] - median) / x;
        }

        return result;
    }
};