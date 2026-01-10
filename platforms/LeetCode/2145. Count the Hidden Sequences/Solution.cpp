#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long sum = 0;
        long maxx = 0;
        long minn = 0;

        for (int difference : differences)
        {
            sum += difference;
            maxx = max(maxx, sum);
            minn = min(minn, sum);
        }

        return max(0L, upper - lower - maxx + minn + 1);
    }
};