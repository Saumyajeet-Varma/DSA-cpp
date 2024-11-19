#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_set<int> distinctEl;
        long long sum = 0;
        long long maxx = 0;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            if (distinctEl.find(nums[right]) == distinctEl.end())
            {
                sum += nums[right];
                distinctEl.insert(nums[right]);
                if (right - left + 1 == k)
                {
                    maxx = max(maxx, sum);
                    sum -= nums[left];
                    distinctEl.erase(nums[left]);
                    left++;
                }
            }
            else
            {
                while (nums[left] != nums[right])
                {
                    sum -= nums[left];
                    distinctEl.erase(nums[left]);
                    left++;
                }
                left++;
            }
        }
        return maxx;
    }
};