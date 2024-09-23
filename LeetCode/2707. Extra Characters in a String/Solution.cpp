#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_set<string> dictSet;
        int n = s.length();
        for (string word : dictionary)
        {
            dictSet.insert(word);
        }
        vector<int> delCount(n + 1);
        for (int r = 1; r <= n; r++)
        {
            delCount[r] = 1 + delCount[r - 1];
            for (int l = r; l > 0; l--)
            {
                string word = s.substr(l - 1, r - l + 1);
                if (dictSet.count(word))
                    delCount[r] = min(delCount[r], delCount[l - 1]);
            }
        }
        return delCount[n];
    }
};