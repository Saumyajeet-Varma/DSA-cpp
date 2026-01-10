#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> a = arr;
        sort(a.begin(), a.end());
        unordered_map<int, int> mp;
        int n = arr.size();
        int rank = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && a[i] != a[i - 1])
                rank++;
            mp[a[i]] = rank;
        }
        for (auto &it : arr)
        {
            it = mp[it];
        }
        return arr;
    }
};