#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getPairs(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int l = 0, r = n - 1;
        while (l < r)
        {
            long long sum = arr[l] + arr[r];
            if (sum > 0)
                r--;
            else if (sum < 0)
                l++;
            else
            {
                result.push_back({arr[l], arr[r]});
                while (l < r && arr[l] == arr[l + 1])
                {
                    l++;
                }
                while (l < r && arr[r] == arr[r - 1])
                {
                    r--;
                }
                l++;
                r--;
            }
        }
        return result;
    }
};