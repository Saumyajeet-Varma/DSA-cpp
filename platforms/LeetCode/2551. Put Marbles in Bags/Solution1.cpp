#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        if (k == 1)
            return 0;

        int n = weights.size();

        long long maxx = weights[0] + weights[n - 1];
        long long minn = weights[0] + weights[n - 1];

        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;

        for (int i = 1; i < n; i++)
        {
            maxpq.push(weights[i] + weights[i - 1]);
            minpq.push(weights[i] + weights[i - 1]);
        }

        for (int i = 1; i < k; i++)
        {
            maxx += maxpq.top();
            maxpq.pop();

            minn += minpq.top();
            minpq.pop();
        }

        return maxx - minn;
    }
};