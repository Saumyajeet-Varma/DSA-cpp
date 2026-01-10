#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();

        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({double((double)val[i] / (double)wt[i]), wt[i]});
        }

        double totalVal = 0;

        while (capacity > 0 && !pq.empty())
        {
            auto topp = pq.top();
            pq.pop();

            double unitVal = topp.first;
            int weight = topp.second;

            if (weight <= capacity)
            {
                totalVal += weight * unitVal;
                capacity -= weight;
            }
            else
            {
                totalVal += capacity * unitVal;
                capacity = 0;
            }
        }

        return totalVal;
    }
};