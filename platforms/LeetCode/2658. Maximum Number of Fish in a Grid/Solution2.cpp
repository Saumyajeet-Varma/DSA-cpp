#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxFish = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] > 0)
                {
                    int currFish = 0;
                    queue<pair<int, int>> que;
                    que.push({i, j});
                    while (!que.empty())
                    {
                        auto it = que.front();
                        que.pop();

                        int row = it.first;
                        int col = it.second;

                        if (grid[row][col] > 0)
                        {
                            currFish += grid[row][col];
                            grid[row][col] = 0;

                            if (row > 0 && grid[row - 1][col] > 0)
                                que.push({row - 1, col});
                            if (row < rows - 1 && grid[row + 1][col] > 0)
                                que.push({row + 1, col});
                            if (col > 0 && grid[row][col - 1] > 0)
                                que.push({row, col - 1});
                            if (col < cols - 1 && grid[row][col + 1] > 0)
                                que.push({row, col + 1});
                        }
                    }

                    maxFish = max(maxFish, currFish);
                }
            }
        }

        return maxFish;
    }
};