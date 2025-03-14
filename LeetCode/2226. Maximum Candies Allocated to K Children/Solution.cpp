#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        int n = candies.size();

        int result = 0;
        long long left = 1;
        long long right = *max_element(candies.begin(), candies.end());

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long childrenCount = 0;

            for (int pile : candies)
            {
                childrenCount += pile / mid;
            }

            if (childrenCount >= k)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};