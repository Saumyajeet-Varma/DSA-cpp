#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isVowelStr(string &s)
    {
        int n = s.length();
        char ch1 = s[0];
        char ch2 = s[n - 1];
        if ((ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u') && (ch2 == 'a' || ch2 == 'e' || ch2 == 'i' || ch2 == 'o' || ch2 == 'u'))
            return true;
        return false;
    }

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> result;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (isVowelStr(words[i]) ? 1 : 0);
        }
        for (auto &query : queries)
        {
            int l = query[0];
            int r = query[1];
            result.push_back(prefix[r + 1] - prefix[l]);
        }
        return result;
    }
};