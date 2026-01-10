#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (vector<int> point : points)
        {
            int x = point[0];
            int y = point[1];

            int dist = pow(x, 2) + pow(y, 2);

            pq.push({dist, {x, y}});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;

        while (!pq.empty())
        {
            auto el = pq.top();
            pq.pop();

            result.push_back({el.second.first, el.second.second});
        }

        return result;
    }
};
