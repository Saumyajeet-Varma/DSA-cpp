#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        vector<pair<int, int>> freqArr;

        for (int num : nums)
        {
            freq[num]++;
        }

        for (auto it : freq)
        {
            freqArr.push_back({it.second, it.first});
        }

        sort(freqArr.rbegin(), freqArr.rend());

        for (int i = 0; i < k; i++)
        {
            result.push_back(freqArr[i].second);
        }

        return result;
    }
};