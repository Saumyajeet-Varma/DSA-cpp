#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length();

        int result = INT_MAX;

        for (int i = 0; i <= n - k; i++)
        {
            int whiteCount = 0;

            for (int j = i; j < i + k; j++)
            {
                if (blocks[j] == 'W')
                    whiteCount++;
            }

            result = min(result, whiteCount);
        }

        return result;
    }
};