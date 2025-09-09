#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        if (s == "a")
            return 0;

        int n = s.length();

        if (n == 1)
            return 26 - int(s[0] - 'a');

        vector<int> hash(26, 0);

        for (char c : s)
        {
            hash[c - 'a']++;
        }

        if (hash[0] == n)
            return 0;

        for (int i = 1; i < 26; i++)
        {
            if (hash[i] > 0)
                return 26 - i;
        }

        return -1;
    }
};