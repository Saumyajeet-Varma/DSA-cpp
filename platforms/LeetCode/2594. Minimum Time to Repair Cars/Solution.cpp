#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool canRepair(vector<int> &ranks, int cars, long long result)
    {
        int n = ranks.size();

        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            count += sqrt((result * 1.0) / ranks[i]);
        }

        return count >= cars * 1LL;
    }

public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long left = 1;
        long long right = 1LL * (*max_element(ranks.begin(), ranks.end())) * cars * cars;

        long long result = right;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;

            if (canRepair(ranks, cars, mid))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }
};