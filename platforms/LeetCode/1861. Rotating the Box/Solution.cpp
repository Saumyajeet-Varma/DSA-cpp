#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> rotate(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++)
        {
            int bottom = m - 1;
            for (int j = m - 1; j >= 0; j--)
            {
                if (box[i][j] == '#')
                {
                    rotate[bottom][n - 1 - i] = '#';
                    bottom--;
                }
                else if (box[i][j] == '*')
                {
                    rotate[j][n - 1 - i] = '*';
                    bottom = j - 1;
                }
            }
        }
        return rotate;
    }
};