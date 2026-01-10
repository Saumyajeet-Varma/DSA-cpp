#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int row = arr.size();
        int col = arr[0].size();
        int ans = -1;
        int maxcount = 0;
        for (int i = 0; i < row; i++)
        {
            int count = 0;
            for (int j = 0; j < col; j++)
            {
                if (arr[i][j] == 1)
                    count++;
            }
            if (maxcount < count)
            {
                ans = i;
                maxcount = count;
            }
        }
        return ans;
    }
};