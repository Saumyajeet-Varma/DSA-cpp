#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> shortestTime(n, LLONG_MAX);
        vector<int> count(n, 0);

        for (auto road : roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        shortestTime[0] = 0;
        count[0] = 1;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            long long time = topp.first;
            int node = topp.second;

            if (time > shortestTime[node])
                continue;

            for (auto it : adj[node])
            {
                int nbr = it.first;
                int roadTime = it.second;

                if (time + roadTime < shortestTime[nbr])
                {
                    shortestTime[nbr] = time + roadTime;
                    count[nbr] = count[node];
                    pq.push({shortestTime[nbr], nbr});
                }
                else if (time + roadTime == shortestTime[nbr])
                {
                    count[nbr] = (count[nbr] + count[node]) % MOD;
                }
            }
        }

        return count[n - 1];
    }
};