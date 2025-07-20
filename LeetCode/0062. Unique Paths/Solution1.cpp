#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int i, int j, int m, int n)
    {
        if (i == 0 && j == 0)
            return 1;

        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;

        int up = recfunc(i - 1, j, m, n);
        int left = recfunc(i, j - 1, m, n);

        return up + left;
    }

public:
    int uniquePaths(int m, int n)
    {
        return recfunc(m - 1, n - 1, m, n);
    }
};