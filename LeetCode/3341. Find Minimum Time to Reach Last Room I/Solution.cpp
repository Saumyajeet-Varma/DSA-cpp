#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minpq;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        moveTime[0][0] = 0;
        minpq.push({0, 0, 0});

        while (!minpq.empty())
        {
            auto curr = minpq.top();
            minpq.pop();

            int currTime = curr[0];
            int currRow = curr[1];
            int currCol = curr[2];

            if (currTime >= dp[currRow][currCol])
                continue;

            if (currRow == n - 1 && currCol == m - 1)
                return currTime;

            dp[currRow][currCol] = currTime;

            for (auto &dir : dirs)
            {
                int nxtRow = currRow + dir[0];
                int nxtCol = currCol + dir[1];

                if (nxtRow >= 0 && nxtRow < n && nxtCol >= 0 && nxtCol < m && dp[nxtRow][nxtCol] == INT_MAX)
                {
                    int nxtTime = max(currTime, moveTime[nxtRow][nxtCol]) + 1;
                    minpq.push({nxtTime, nxtRow, nxtCol});
                }
            }
        }

        return -1;
    }
};