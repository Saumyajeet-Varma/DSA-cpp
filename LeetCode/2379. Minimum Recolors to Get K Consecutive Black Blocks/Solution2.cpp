#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length();

        int whiteCount = 0;

        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                whiteCount++;
        }

        int result = whiteCount;

        for (int i = k; i < n; i++)
        {
            if (blocks[i - k] == 'W')
                whiteCount--;
            if (blocks[i] == 'W')
                whiteCount++;

            result = min(result, whiteCount);
        }

        return result;
    }
};