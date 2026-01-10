#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compressedString(string word)
    {
        string result = "";
        int n = word.size();
        int count = 1;
        char ch = word[0];
        for (int i = 1; i < n; i++)
        {
            if (word[i] == ch && count < 9)
                count++;
            else
            {
                result.push_back(count + '0');
                result.push_back(ch);
                ch = word[i];
                count = 1;
            }
        }
        result.push_back(count + '0');
        result.push_back(ch);
        return result;
    }
};