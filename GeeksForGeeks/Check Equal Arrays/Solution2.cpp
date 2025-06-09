#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkEqual(vector<int> &a, vector<int> &b)
    {
        if (a.size() != b.size())
            return false;

        int n = a.size();

        unordered_map<int, int> nums;

        for (int i = 0; i < n; i++)
        {
            nums[a[i]]++;
            nums[b[i]]--;
        }

        for (auto it : nums)
        {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};