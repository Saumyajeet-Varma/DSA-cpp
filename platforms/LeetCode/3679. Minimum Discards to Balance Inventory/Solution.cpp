#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        int n = arrivals.size();

        int result = 0;
        unordered_map<int, int> mpp;
        queue<pair<int, int>> que;

        for (int i = 0; i < n; i++)
        {
            while (!que.empty() && que.front().second < i - w + 1)
            {
                auto curr = que.front();
                que.pop();

                mpp[curr.first]--;

                if (mpp[curr.first] == 0)
                {
                    mpp.erase(curr.first);
                }
            }

            if (mpp[arrivals[i]] < m)
            {
                mpp[arrivals[i]]++;
                que.push({arrivals[i], i});
            }
            else
            {
                result++;
            }
        }

        return result;
    }
};