#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        int n1 = str1.length();
        int n2 = str2.length();

        if (n1 > n2)
            return false;

        bool prefix = str2.substr(0, n1) == str1;
        bool suffix = str2.substr(n2 - n1, n1) == str1;

        return prefix && suffix;
    }

public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int count = 0;
        int n = words.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                    count++;
            }
        }

        return count;
    }
};