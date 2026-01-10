#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();

        int count = 0;
        int letter = 0;

        int freq[3] = {0};

        int l = 0;
        int r = 0;

        while (r < n)
        {
            freq[s[r] - 'a']++;

            if (freq[s[r] - 'a'] == 1)
                letter++;

            while (letter == 3)
            {
                freq[s[l] - 'a']--;

                if (freq[s[l] - 'a'] == 0)
                    letter--;

                l++;
            }

            count += l;

            r++;
        }

        return count;
    }
};