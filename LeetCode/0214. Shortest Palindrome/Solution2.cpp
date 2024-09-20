#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceed for only one test case.
class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    string shortestPalindrome(string s)
    {
        int n = s.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (isPalindrome(s, 0, i))
            {
                string temp = s.substr(i + 1);
                reverse(temp.begin(), temp.end());
                return temp + s;
            }
        }
        return s;
    }
};
