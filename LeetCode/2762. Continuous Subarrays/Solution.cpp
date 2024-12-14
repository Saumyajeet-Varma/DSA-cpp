#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = 0;
        map<int, int> mp;
        long long count = 0;
        while (r < n)
        {
            mp[nums[r]]++;
            while (mp.rbegin()->first - mp.begin()->first > 2)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
};