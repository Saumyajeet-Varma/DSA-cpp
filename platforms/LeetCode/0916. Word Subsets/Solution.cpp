#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<char, int> req;
        for (string str : words2)
        {
            unordered_map<char, int> curr;
            for (char ch : str)
            {
                curr[ch]++;
                req[ch] = max(req[ch], curr[ch]);
            }
        }
        vector<string> ans;
        for (string str : words1)
        {
            unordered_map<int, int> curr;
            for (char ch : str)
            {
                curr[ch]++;
            }
            bool flag = true;
            for (auto it : req)
            {
                char ch = it.first;
                int freq = it.second;
                if (curr[ch] < freq)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.push_back(str);
        }
        return ans;
    }
};