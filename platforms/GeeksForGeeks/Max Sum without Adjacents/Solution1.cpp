#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int idx, vector<int> &arr)
    {
        if (idx == 0)
            return arr[0];

        if (idx < 0)
            return 0;

        int take = arr[idx] + recfunc(idx - 2, arr);
        int notTake = recfunc(idx - 1, arr);

        return max(take, notTake);
    }

public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        return recfunc(n - 1, arr);
    }
};