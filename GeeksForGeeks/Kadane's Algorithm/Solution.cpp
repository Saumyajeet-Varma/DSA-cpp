#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr)
    {
        long long max = arr[0];
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (max < sum)
                max = sum;
            if (sum < 0)
                sum = 0;
        }
        return max;
    }
};