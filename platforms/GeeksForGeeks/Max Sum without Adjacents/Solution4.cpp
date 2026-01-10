#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();

        int prev1 = arr[0];
        int prev2 = 0;
        int curr;

        for (int i = 0; i < n; i++)
        {
            int take = arr[i];
            int notTake = prev1;

            if (i > 1)
                take += prev2;

            curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};