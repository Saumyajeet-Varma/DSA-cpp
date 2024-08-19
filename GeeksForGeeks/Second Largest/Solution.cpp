#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int print2largest(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1 || n == 0)
            return -1;
        int max = arr[0], second_max = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > second_max)
            {
                if (arr[i] < max)
                {
                    second_max = arr[i];
                }
            }
        }
        return second_max;
    }
};