#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> ans;
        unordered_map<string, int> mpp;
        string word;
        stringstream ss1(s1);
        stringstream ss2(s2);
        while (ss1 >> word)
        {
            mpp[word]++;
        }
        while (ss2 >> word)
        {
            mpp[word]++;
        }
        for (auto it : mpp)
        {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};
