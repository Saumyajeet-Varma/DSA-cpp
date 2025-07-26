#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    bool recfunc(vector<int> &arr, int i, int target)
    {
        if (target == 0)
            return true;

        if (i == 0)
            return arr[0] == target;

        bool notTake = recfunc(arr, i - 1, target);
        bool take = false;

        if (arr[i] <= target)
            take = recfunc(arr, i - 1, target - arr[i]);

        return take || notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        return recfunc(arr, n - 1, sum);
    }
};