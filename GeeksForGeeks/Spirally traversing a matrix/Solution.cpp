#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        vector<int> spiral;

        int rows = mat.size();
        int cols = mat[0].size();

        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                spiral.push_back(mat[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                spiral.push_back(mat[i][right]);
            }
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    spiral.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    spiral.push_back(mat[i][left]);
                }
                left++;
            }
        }

        return spiral;
    }
};