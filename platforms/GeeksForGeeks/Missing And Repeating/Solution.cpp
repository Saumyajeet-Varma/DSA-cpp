#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        vector<int> ans;
        int repeat, miss;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp.find(i) == mp.end())
                miss = i;
            if (mp[i] == 2)
                repeat = i;
        }
        ans.push_back(repeat);
        ans.push_back(miss);
        return ans;
    }
};