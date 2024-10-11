#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        vector<pair<int, int>> arrivals;
        for (int i = 0; i < n; i++)
        {
            arrivals.push_back({times[i][0], i});
        }
        sort(arrivals.begin(), arrivals.end());
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; i++)
        {
            availableChairs.push(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        for (auto it : arrivals)
        {
            int arrivalTime = it.first;
            int nextIndex = it.second;
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrivalTime)
            {
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }
            int chair = availableChairs.top();
            availableChairs.pop();
            if (nextIndex == targetFriend)
                return chair;
            leavingQueue.push({times[nextIndex][1], chair});
        }
        return -1;
    }
};