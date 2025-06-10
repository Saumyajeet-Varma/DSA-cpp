#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool binarySearch(vector<int> arr, int target)
    {
        int n = arr.size();

        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] < target)
            {
                l = mid + 1;
            }
            else if (arr[mid] > target)
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

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][cols - 1])
            {
                return binarySearch(matrix[i], target);
            }
        }

        return false;
    }
};
