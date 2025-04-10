#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long calculate(string numStr, string s, int limit)
    {
        int n = numStr.length();
        int l = s.length();

        int d = n - l;

        if (n < l)
            return 0;

        if (n == l)
            return numStr >= s ? 1 : 0;

        string str = numStr.substr(d, l);

        long long result = 0;

        for (int i = 0; i < d; i++)
        {
            if (limit < (numStr[i] - '0'))
            {
                result += (long)pow(limit + 1, d - i);
                return result;
            }

            result += (long)(numStr[i] - '0') * (long)pow(limit + 1, d - 1 - i);
        }

        if (str >= s)
            result++;

        return result;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);

        return calculate(finishStr, s, limit) - calculate(startStr, s, limit);
    }
};