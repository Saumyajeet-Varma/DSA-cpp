#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int ans = 0;
        int n = values.size();
        int prev = values[0];
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, prev + values[i] - i);
            prev = max(prev, values[i] + i);
        }
        return ans;
    }
};