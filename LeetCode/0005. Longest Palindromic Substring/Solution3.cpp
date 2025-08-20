#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int maxlen(string s, int left, int right)
    {
        int n = s.length();

        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }

        return right - left - 1;
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.length();

        if (n == 0 || n == 1)
            return s;

        int start = 0;
        int end = 0;
        int maxx = 0;

        for (int i = 0; i < n; i++)
        {
            int oddLen = maxlen(s, i, i);
            int evenLen = maxlen(s, i, i + 1);

            maxx = max(oddLen, evenLen);

            if (maxx > end - start + 1)
            {
                start = i - (maxx - 1) / 2;
                end = i + maxx / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};