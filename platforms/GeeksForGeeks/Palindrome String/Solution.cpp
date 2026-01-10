#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};