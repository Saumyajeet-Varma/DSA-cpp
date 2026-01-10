#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int ans = INT_MAX;
        int n = timePoints.size();
        vector<int> times;
        for (string i : timePoints)
        {
            times.push_back(stoi(i.substr(0, 2)) * 60 + stoi(i.substr(3, 2)));
        }
        sort(times.begin(), times.end());
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, times[i] - times[i - 1]);
        }
        ans = min(ans, 1440 - abs(times[n - 1] - times[0]));
        return ans;
    }
};