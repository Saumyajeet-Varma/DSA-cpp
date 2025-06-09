#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkEqual(vector<int> &a, vector<int> &b)
    {
        if (a.size() != b.size())
            return false;

        int n = a.size();

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                return false;
        }

        return true;
    }
};