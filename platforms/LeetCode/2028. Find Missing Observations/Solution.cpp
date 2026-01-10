#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += rolls[i];
        }
        int totalSum = (m + n) * mean;
        int reqSum = totalSum - sum;
        if (reqSum < n || reqSum > 6 * n)
            return {};
        int base = reqSum / n;
        int incr = reqSum % n;
        vector<int> result(n, base);
        for (int i = 0; i < incr; i++)
        {
            result[i]++;
        }
        return result;
    }
};