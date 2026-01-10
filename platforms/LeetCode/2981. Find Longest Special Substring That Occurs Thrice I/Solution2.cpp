#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.length();
        int maxLen = -1;
        for (int len = 1; len <= n; len++)
        {
            unordered_map<string, int> freq;
            for (int i = 0; i <= n - len; i++)
            {
                string subStr = s.substr(i, len);
                bool specialStr = true;
                for (int j = 1; j < len; j++)
                {
                    if (subStr[j] != subStr[0])
                    {
                        specialStr = false;
                        break;
                    }
                }
                if (specialStr)
                {
                    freq[subStr]++;
                    if (freq[subStr] >= 3)
                        maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};