#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubset(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> nums;

        for (int num : a)
        {
            nums[num]++;
        }

        for (int num : b)
        {
            if (!nums[num])
                return false;

            nums[num]--;

            if (nums[num] == 0)
                nums.erase(num);
        }

        return true;
    }
};