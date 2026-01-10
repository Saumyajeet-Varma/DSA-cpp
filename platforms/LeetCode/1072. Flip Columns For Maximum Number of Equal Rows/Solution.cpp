#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        map<string, int> mp;
        for (auto row : matrix)
        {
            int first = row[0];
            string str = "";
            for (int i = 0; i < row.size(); i++)
            {
                str += (first == row[i]) ? '1' : '0';
            }
            mp[str]++;
        }
        int maxx = 0;
        for (auto it : mp)
        {
            maxx = max(maxx, it.second);
        }
        return maxx;
    }
};