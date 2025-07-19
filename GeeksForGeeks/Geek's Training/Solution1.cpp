#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceeded
class Solution
{
private:
    int recfunc(int day, int last, vector<vector<int>> &arr)
    {
        if (day == 0)
        {
            int maxx = 0;

            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                    maxx = max(maxx, arr[0][i]);
            }

            return maxx;
        }

        int maxx = 0;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int points = arr[day][i] + recfunc(day - 1, i, arr);
                maxx = max(maxx, points);
            }
        }

        return maxx;
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        return recfunc(n - 1, 3, arr);
    }
};