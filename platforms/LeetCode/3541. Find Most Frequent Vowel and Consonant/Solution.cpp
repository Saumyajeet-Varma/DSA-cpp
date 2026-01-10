#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        unordered_map<char, int> vow;
        unordered_map<char, int> con;

        for (char ch : s)
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vow[ch]++;
            }
            else
            {
                con[ch]++;
            }
        }

        int maxV = 0;
        int maxC = 0;

        for (auto it : vow)
        {
            maxV = max(maxV, it.second);
        }

        for (auto it : con)
        {
            maxC = max(maxC, it.second);
        }

        return maxV + maxC;
    }
};