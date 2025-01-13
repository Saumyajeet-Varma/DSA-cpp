#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> freq(26, 0);
        for (char ch : s)
        {
            freq[ch - 'a']++;
        }

        int result = 0;
        for (int frequency : freq)
        {
            if (frequency == 0)
                continue;

            if (frequency % 2 == 0)
                result += 2;
            else
                result += 1;
        }

        return result;
    }
};