#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int i = 0, ans = 1, n = arr.size(), count = 0;
        while (count != k)
        {
            if ((i < n && ans < arr[i]) || i >= n)
                count++;
            if (i < n && ans == arr[i])
                i++;
            ans++;
        }
        return ans - 1;
    }
};