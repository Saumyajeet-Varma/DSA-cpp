#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recfunc(int i, int j, vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        if (i == n - 1)
            return triangle[i][j];

        int left = recfunc(i + 1, j, triangle);
        int right = recfunc(i + 1, j + 1, triangle);

        return triangle[i][j] + min(left, right);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return recfunc(0, 0, triangle);
    }
};