#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            for (auto num : nums[i])
            {
                vec.push_back({num, i});
            }
        }
        sort(vec.begin(), vec.end());
        int left = 0, right = 0, k = 0, v = vec.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        while (right < v)
        {
            if (!mpp[vec[right].second]++)
                k++;
            if (k == n)
            {
                while (mpp[vec[left].second] > 1)
                {
                    mpp[vec[left++].second]--;
                }
                if (ans.empty() || ans[1] - ans[0] > vec[right].first - vec[left].first)
                    ans = vector<int>{vec[left].first, vec[right].first};
            }
            right++;
        }
        return ans;
    }
};