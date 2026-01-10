#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            for (int i = 0; i < right - left; i++)
            {
                int top = left;
                int bottom = right;

                int temp = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }

            left++;
            right--;
        }
    }
};