#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if (s.length() < k)
            return false;
        sort(s.begin(), s.end());
        int oddCount = 0;
        int n = s.length();
        int i = 0;
        while (i < n)
        {
            char curr = s[i];
            int count = 0;
            while (i < n && s[i] == curr)
            {
                count++;
                i++;
            }
            if (count % 2 != 0)
                oddCount++;
        }
        return oddCount <= k;
    }
};