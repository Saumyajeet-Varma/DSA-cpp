#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceed
class Solution
{
private:
    bool isPalindrome(const string &s)
    {
        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.length();

        if (n <= 1 || (s == string(s.rbegin(), s.rend())))
            return s;

        int maxLen = 1;
        string maxStr = s.substr(0, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + maxLen; j <= n; j++)
            {
                if (j - i > maxLen && isPalindrome(s.substr(i, j - i)))
                {
                    maxLen = j - i;
                    maxStr = s.substr(i, j - i);
                }
            }
        }

        return maxStr;
    }
};