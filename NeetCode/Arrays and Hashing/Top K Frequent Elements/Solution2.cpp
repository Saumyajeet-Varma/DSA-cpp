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

        vector<pair<int, int>> freqArr;

        for (auto it : freq)
        {
            freqArr.push_back({it.second, it.first});
        }

        sort(freqArr.rbegin(), freqArr.rend());

        vector<int> result;

        for (int i = 0; i < k; i++)
        {
            result.push_back(freqArr[i].second);
        }

        return result;
    }
};
