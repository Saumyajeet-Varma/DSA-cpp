#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        int i = n - 1;

        while (digits[i] == 9 && i >= 0)
        {
            digits[i] = 0;
            i--;
        }

        if (i >= 0)
        {
            digits[i] += 1;
            return digits;
        }

        vector<int> result(n + 1, 0);
        result[0] = 1;

        return result;
    }
};
