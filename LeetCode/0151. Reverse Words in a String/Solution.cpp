#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();

        string result = "";

        vector<string> words;

        int i = 0;
        string str = "";

        while (i < n)
        {
            if (s[i] == ' ')
            {
                if (str != "")
                    words.push_back(str);

                str = "";
            }
            else
            {
                str += s[i];
            }

            i++;
        }

        if (i == n && str != "")
            words.push_back(str);

        int wordsLen = words.size();

        for (int j = wordsLen - 1; j >= 0; j--)
        {
            if (j == 0)
                result += words[j];
            else
                result += words[j] + " ";
        }

        return result;
    }
};