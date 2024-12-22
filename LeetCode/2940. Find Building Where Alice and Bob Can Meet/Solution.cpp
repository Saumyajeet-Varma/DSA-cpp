#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getIndex(int height, int index, vector<pair<int, int>> &relHeight)
    {
        int ans = INT_MAX;
        for (auto it : relHeight)
        {
            if (it.first <= height)
                break;
            if (it.second >= index)
                ans = min(ans, it.second);
        }
        return ans == INT_MAX ? -1 : ans;
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n1 = heights.size();
        int n2 = queries.size();
        vector<int> result(n2);
        vector<pair<int, int>> relHeight;
        for (int i = 1; i < n1; i++)
        {
            if (heights[i - 1] < heights[i])
                relHeight.push_back({heights[i], i});
        }
        sort(relHeight.rbegin(), relHeight.rend());
        for (int i = 0; i < n2; i++)
        {
            int aliceIndex = queries[i][0];
            int bobIndex = queries[i][1];
            if (aliceIndex == bobIndex)
                result[i] = aliceIndex;
            else
            {
                int aliceHeight = heights[aliceIndex];
                int bobHeight = heights[bobIndex];
                int maxIndex = max(aliceIndex, bobIndex);
                int maxHeight = max(aliceHeight, bobHeight);
                if ((aliceIndex > bobIndex && aliceHeight > bobHeight) || (bobIndex > aliceIndex && bobHeight > aliceHeight))
                    result[i] = maxIndex;
                else
                    result[i] = getIndex(maxHeight, maxIndex, relHeight);
            }
        }
        return result;
    }
};