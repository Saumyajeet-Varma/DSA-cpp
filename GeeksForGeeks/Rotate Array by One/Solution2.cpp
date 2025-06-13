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

        reverse(arr.begin(), arr.end() - 1);
        reverse(arr.begin(), arr.end());
    }
};