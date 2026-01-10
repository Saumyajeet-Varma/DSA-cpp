#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();

        long long count = 0;
        long long left = 0;

        deque<int> dqMin;
        deque<int> dqMax;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                dqMin.clear();
                dqMax.clear();

                left = i + 1;

                continue;
            }

            while (!dqMin.empty() && nums[dqMin.back()] >= nums[i])
            {
                dqMin.pop_back();
            }
            dqMin.push_back(i);

            while (!dqMax.empty() && nums[dqMax.back()] <= nums[i])
            {
                dqMax.pop_back();
            }
            dqMax.push_back(i);

            if (nums[dqMin.front()] == minK && nums[dqMax.front()] == maxK)
            {
                int right = min(dqMin.front(), dqMax.front());
                count += right - left + 1;
            }
        }

        return count;
    }
};