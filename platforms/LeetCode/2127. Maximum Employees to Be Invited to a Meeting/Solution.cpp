#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();

        vector<int> inDegree(n, 0);
        vector<int> chain(n, 0);
        vector<bool> vis(n, false);
        queue<int> que;

        for (int node : favorite)
        {
            inDegree[node]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (!inDegree[i])
                que.push(i);
        }

        while (!que.empty())
        {
            int node = que.front();
            que.pop();

            vis[node] = true;
            int next = favorite[node];
            chain[next] = chain[node] + 1;

            inDegree[next]--;
            if (inDegree[next] == 0)
                que.push(next);
        }

        int maxCycle = 0;
        int total = 0;

        for (int node = 0; node < n; node++)
        {
            if (!vis[node])
            {
                int curr = node;
                int len = 0;

                while (!vis[curr])
                {
                    vis[curr] = true;
                    curr = favorite[curr];
                    len++;
                }

                if (len == 2)
                    total += (2 + chain[node] + chain[favorite[node]]);
                else
                    maxCycle = max(maxCycle, len);
            }
        }

        return max(total, maxCycle);
    }
};