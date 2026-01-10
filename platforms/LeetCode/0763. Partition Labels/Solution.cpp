#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length();

        unordered_map<char, pair<int, int>> mp;
        vector<pair<int, int>> vec;
        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = {i, i};

            mp[s[i]].second = i;
        }

        for (auto &it : mp)
        {
            vec.push_back(it.second);
        }

        int v = vec.size();

        sort(vec.begin(), vec.end());

        int low = vec[0].first;
        int high = vec[0].second;

        for (int i = 1; i < v; i++)
        {
            if (vec[i].first <= high)
            {
                high = max(high, vec[i].second);
            }
            else
            {
                result.push_back(high - low + 1);
                low = vec[i].first;
                high = vec[i].second;
            }
        }

        result.push_back(high - low + 1);

        return result;
    }
};