#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<string> result(n);
        vector<pair<int, int>> scoreIndex;
        for (int i = 0; i < n; i++)
        {
            scoreIndex.push_back({score[i], i});
        }
        sort(scoreIndex.rbegin(), scoreIndex.rend());
        for (int i = 0; i < n; i++)
        {
            int index = scoreIndex[i].second;
            switch (i)
            {
            case 0:
                result[index] = "Gold Medal";
                break;
            case 1:
                result[index] = "Silver Medal";
                break;
            case 2:
                result[index] = "Bronze Medal";
                break;
            default:
                result[index] = to_string(i + 1);
            }
        }
        return result;
    }
};