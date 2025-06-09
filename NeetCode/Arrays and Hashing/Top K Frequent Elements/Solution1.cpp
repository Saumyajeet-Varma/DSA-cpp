#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto it : freq)
        {
            minHeap.push({it.second, it.first});

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> result;

        for (int i = 0; i < k; i++)
        {
            pair<int, int> topp = minHeap.top();
            minHeap.pop();

            result.push_back(topp.second);
        }

        return result;
    }
};
