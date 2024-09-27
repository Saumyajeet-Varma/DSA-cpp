#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
public:
    vector<pair<int, int>> ranges;
    vector<pair<int, int>> eventTime;
    MyCalendarTwo()
    {
        // We don't need it here
    }

    bool book(int start, int end)
    {
        for (auto &it : eventTime)
        {
            if (max(start, it.first) < min(end, it.second))
                return false;
        }
        for (auto it : ranges)
        {
            if (max(start, it.first) < min(end, it.second))
                eventTime.push_back({max(start, it.first), min(end, it.second)});
        }
        ranges.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */