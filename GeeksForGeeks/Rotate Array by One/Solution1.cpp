#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 0 || n == 1)
            return;

        int lastEl = arr[n - 1];

        for (int i = n - 1; i >= 1; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = lastEl;
    }
};