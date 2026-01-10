#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        long long ans = LLONG_MAX;

        int rows = grid.size();
        int cols = grid[0].size();

        long long row1Sum = 0;
        long long row2Sum = 0;

        for (int i = 0; i < cols; i++)
        {
            row1Sum += grid[0][i];
        }

        for (int i = 0; i < cols; i++)
        {
            row1Sum -= grid[0][i];
            ans = min(ans, max(row1Sum, row2Sum));
            row2Sum += grid[1][i];
        }

        return ans;
    }
};