#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int k = unordered_set<int>(nums.begin(), nums.end()).size();

        int count = 0;

        unordered_map<int, int> mpp;

        int left = 0;
        int right = 0;

        while (right < n)
        {
            mpp[nums[right]]++;

            while (mpp.size() == k)
            {
                count += n - right;

                mpp[nums[left]]--;

                if (mpp[nums[left]] == 0)
                    mpp.erase(nums[left]);

                left++;
            }

            right++;
        }

        return count;
    }
};