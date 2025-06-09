#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> seen;

        for (int num : nums)
        {
            if (seen[num])
            {
                return num;
            }

            seen[num]++;
        }

        return -1;
    }
};