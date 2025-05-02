#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int len = dominoes.size();

        int prev = 0;
        string s = "L" + dominoes + "R";

        int n = s.size();

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '.')
                continue;

            if (s[prev] == s[i])
            {
                for (int k = prev + 1; k < i; k++)
                {
                    s[k] = s[i];
                }
            }
            else if (s[prev] == 'R' && s[i] == 'L')
            {
                int left = prev + 1;
                int right = i - 1;

                while (left < right)
                {
                    s[left] = 'R';
                    left++;

                    s[right] = 'L';
                    right--;
                }
            }

            prev = i;
        }

        return s.substr(1, len);
    }
};