#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double gain(int pass, int total)
    {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto c : classes)
        {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents)
        {
            auto topp = pq.top();
            pq.pop();
            int pass = topp.second.first;
            int total = topp.second.second;
            pq.push({gain(pass + 1, total + 1), {pass + 1, total + 1}});
            extraStudents--;
        }
        double sum = 0;
        while (!pq.empty())
        {
            auto topp = pq.top();
            pq.pop();
            sum += (double)topp.second.first / topp.second.second;
        }
        return sum / classes.size();
    }
};