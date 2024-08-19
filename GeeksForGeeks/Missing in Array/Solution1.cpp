#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(int n, vector<int> &arr)
    {
        int arrSum = 0;
        int sum = (n * (n + 1)) / 2;
        for (int i = 0; i < arr.size(); i++)
        {
            arrSum += arr[i];
        }
        return sum - arrSum;
    }
};