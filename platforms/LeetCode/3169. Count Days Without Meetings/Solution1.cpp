#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int nonMeetDays = 0;
        int temp = 1;

        sort(meetings.begin(), meetings.end());

        for (auto &meeting : meetings)
        {
            nonMeetDays += max(0, meeting[0] - temp);
            temp = max(temp, meeting[1] + 1);

            if (temp > days)
                break;
        }

        return nonMeetDays + max(0, days - temp + 1);
    }
};