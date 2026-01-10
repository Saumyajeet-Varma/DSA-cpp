#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int r = rows * cols - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            int val = matrix[mid / cols][mid % cols];

            if (val < target)
            {
                l = mid + 1;
            }
            else if (val > target)
            {
                r = mid - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
