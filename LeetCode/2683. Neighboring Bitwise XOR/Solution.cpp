#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int result = 0;
        int n = derived.size();
        for (int i = 0; i < n; i++)
        {
            result ^= derived[i];
        }
        return result == 0;
    }
};