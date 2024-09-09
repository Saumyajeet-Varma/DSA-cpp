#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> mat(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int k = 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                mat[top][i] = k;
                k++;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                mat[i][right] = k;
                k++;
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    mat[bottom][i] = k;
                    k++;
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    mat[i][left] = k;
                    k++;
                }
                left++;
            }
        }
        return mat;
    }
};