#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int rows = isWater.size();
        int cols = isWater[0].size();

        vector<vector<int>> height(rows, vector<int>(cols, rows + cols));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (isWater[i][j] == 1)
                    height[i][j] = 0;
                else
                {
                    if (i > 0)
                        height[i][j] = min(height[i][j], height[i - 1][j] + 1);
                    if (j > 0)
                        height[i][j] = min(height[i][j], height[i][j - 1] + 1);
                }
            }
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                if (i < rows - 1)
                    height[i][j] = min(height[i][j], height[i + 1][j] + 1);
                if (j < cols - 1)
                    height[i][j] = min(height[i][j], height[i][j + 1] + 1);
            }
        }

        return height;
    }
};