#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isAlphanumeric(char ch)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            return true;
        }

        return false;
    }

public:
    bool isPalindrome(string s)
    {
        int n = s.length();

        int l = 0;
        int r = n - 1;

        while (l < r)
        {
            while (!isAlphanumeric(s[l]))
            {
                l++;

                if (l == n)
                {
                    return true;
                }
            }

            while (!isAlphanumeric(s[r]))
            {
                r--;

                if (r == -1)
                {
                    return true;
                }
            }

            if (tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
