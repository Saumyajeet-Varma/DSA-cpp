#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;

        for (int stone : stones)
        {
            pq.push(stone);
        }

        while (pq.size() > 1)
        {
            int stone1 = pq.top();
            pq.pop();

            int stone2 = pq.top();
            pq.pop();

            if (stone1 > stone2)
            {
                pq.push(stone1 - stone2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};