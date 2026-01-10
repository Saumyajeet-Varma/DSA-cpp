#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int val1 = -1, val2 = -1;
        int low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
            {
                val1 = arr[mid];
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x)
            {
                val2 = arr[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ans.push_back(val1);
        ans.push_back(val2);
        return ans;
    }
};