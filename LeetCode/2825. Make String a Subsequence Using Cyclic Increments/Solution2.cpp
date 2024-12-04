#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int index = 0;
        int len = str2.length();
        for (char ch : str1)
        {
            if (index < len && (str2[index] - ch + 26) % 26 <= 1)
                index++;
        }
        return index == len;
    }
};