#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 100000;

public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        if (start == end)
            return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(100000, 1e9);

        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            int steps = topp.first;
            int node = topp.second;

            for (int num : arr)
            {
                int newStart = (node * num) % MOD;

                if (steps + 1 < dist[newStart])
                {
                    dist[newStart] = steps + 1;

                    if (newStart == end)
                        return dist[newStart];

                    pq.push({dist[newStart], newStart});
                }
            }
        }

        return -1;
    }
};
