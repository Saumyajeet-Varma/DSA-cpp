#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> seen;

        for (int num : nums)
        {
            if (seen[num])
            {
                return true;
            }

            seen[num]++;
        }

        return false;
    }
};
