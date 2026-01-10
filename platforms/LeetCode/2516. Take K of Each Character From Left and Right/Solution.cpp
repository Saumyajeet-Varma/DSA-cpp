#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int n = s.length();
        int ans = n;
        int l = 0, r = 0;
        int a = 0, b = 0, c = 0;
        int A = 0, B = 0, C = 0;
        for (char ch : s)
        {
            if (ch == 'a')
                A++;
            else if (ch == 'b')
                B++;
            else if (ch == 'c')
                C++;
        }
        if (A < k || B < k || C < k)
            return -1;
        while (r < n)
        {
            if (s[r] == 'a')
                a++;
            if (s[r] == 'b')
                b++;
            if (s[r] == 'c')
                c++;
            r++;
            while (a > A - k || b > B - k || c > C - k)
            {
                if (s[l] == 'a')
                    a--;
                if (s[l] == 'b')
                    b--;
                if (s[l] == 'c')
                    c--;
                l++;
            }
            ans = min(ans, n - (r - l));
        }
        return ans;
    }
};