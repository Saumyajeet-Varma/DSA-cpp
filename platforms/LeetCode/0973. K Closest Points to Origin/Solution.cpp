#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> pq;

        for (vector<int> point : points)
        {
            int x = point[0];
            int y = point[1];

            int dist = pow(x, 2) + pow(y, 2);

            pq.push({dist, point});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;

        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            result.push_back(topp.second);
        }

        return result;
    }
};
