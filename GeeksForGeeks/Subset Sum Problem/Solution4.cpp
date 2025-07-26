#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();

        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);

        prev[0] = true;
        curr[0] = true;

        prev[arr[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                bool notTake = prev[j];
                bool take = false;

                if (arr[i] <= j)
                    take = prev[j - arr[i]];

                curr[j] = take || notTake;
            }

            prev = curr;
        }

        return prev[sum];
    }
};