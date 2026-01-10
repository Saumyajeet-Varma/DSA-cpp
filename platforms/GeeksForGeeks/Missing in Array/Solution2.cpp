#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(int n, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] != i)
                return i;
        }
        return n;
    }
};