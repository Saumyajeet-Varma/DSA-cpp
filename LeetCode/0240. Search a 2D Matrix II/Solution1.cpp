#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool BinarySearch(vector<int> &arr, int n, int target)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int element = arr[mid];
            if (element == target)
                return true;
            else if (element < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

    // Main Function
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            if (BinarySearch(matrix[i], col, target))
                return true;
        }
        return false;
    }
};