#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();

        vector<int> prev(4, 0);

        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});

        for (int day = 1; day < n; day++)
        {
            vector<int> curr(4, 0);
            for (int last = 0; last < 4; last++)
            {
                curr[last] = 0;

                for (int i = 0; i < 3; i++)
                {
                    if (i != last)
                    {
                        int points = arr[day][i] + prev[i];
                        curr[last] = max(curr[last], points);
                    }
                }
            }

            prev = curr;
        }

        return prev[3];
    }
};