#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        int r = robot.size();
        int f = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(r + 1, vector<long long>(f + 1));
        for (int i = 0; i < r; i++)
        {
            dp[i][f] = LLONG_MAX;
        }
        for (int i = f - 1; i >= 0; i--)
        {
            long long prefix = 0;
            deque<pair<int, long long>> dq;
            dq.push_back({r, 0});
            for (int j = r - 1; j >= 0; j--)
            {
                prefix += abs(robot[j] - factory[i][0]);
                while (!dq.empty() && dq.front().first > j + factory[i][1])
                {
                    dq.pop_front();
                }
                while (!dq.empty() && dq.back().second >= dp[j][i + 1] - prefix)
                {
                    dq.pop_back();
                }
                dq.push_back({j, dp[j][i + 1] - prefix});
                dp[j][i] = dq.front().second + prefix;
            }
        }
        return dp[0][0];
    }
};