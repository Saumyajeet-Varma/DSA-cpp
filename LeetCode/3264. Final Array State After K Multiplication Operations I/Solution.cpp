#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }
        while (k > 0)
        {
            auto topp = pq.top();
            pq.pop();
            nums[topp.second] = multiplier * topp.first;
            pq.push({multiplier * topp.first, topp.second});
            k--;
        }
        return nums;
    }
};