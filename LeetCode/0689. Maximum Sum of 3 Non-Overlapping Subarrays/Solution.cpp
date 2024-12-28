#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> sums(n - k + 1, 0);
        vector<int> left(n - k + 1, 0);
        vector<int> right(n - k + 1, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (i >= k - 1)
            {
                sums[i - k + 1] = sum;
                sum -= nums[i - k + 1];
            }
        }
        int index = 0;
        for (int i = 0; i < n - k + 1; i++)
        {
            if (sums[i] > sums[index])
                index = i;
            left[i] = index;
        }
        index = n - k;
        for (int i = n - k; i >= 0; i--)
        {
            if (sums[i] >= sums[index])
                index = i;
            right[i] = index;
        }
        vector<int> result(3, 0);
        int maxSum = 0;
        for (int i = k; i < sums.size() - k; i++)
        {
            int leftIndex = left[i - k];
            int rightIndex = right[i + k];
            int total = sums[leftIndex] + sums[i] + sums[rightIndex];
            if (total > maxSum)
            {
                maxSum = total;
                result = {leftIndex, i, rightIndex};
            }
        }
        return result;
    }
};