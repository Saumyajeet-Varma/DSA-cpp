#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> duplicates(vector<int> arr)
    {
        int n = arr.size();
        if (n == 0 || n == 1)
            return {-1};
        vector<int> result;
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }
        for (auto it : mpp)
        {
            if (it.second > 1)
                result.push_back(it.first);
        }
        if (result.size() == 0)
            return {-1};
        return result;
    }
};