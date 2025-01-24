#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        int n = bt.size();

        sort(bt.begin(), bt.end());

        long long t = 0, waitTime = 0;

        for (int i = 0; i < n; i++)
        {
            waitTime += t;
            t += bt[i];
        }

        return waitTime / n;
    }
};