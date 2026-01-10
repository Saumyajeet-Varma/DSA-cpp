#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        vector<int> ans;
        int first = -1, last = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};