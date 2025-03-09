#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();

        int maxlen = 1;
        int result = 0;

        for (int i = 1; i <= n + k - 2; i++)
        {
            if (colors[i % n] != colors[(i - 1 + n) % n])
                maxlen++;
            else
                maxlen = 1;

            if (maxlen >= k)
                result++;
        }

        return result;
    }
};