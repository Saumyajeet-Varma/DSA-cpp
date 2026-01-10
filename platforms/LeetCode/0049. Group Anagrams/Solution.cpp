#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> anagrams;

        for (string str : strs)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(str);
        }

        for (auto it : anagrams)
        {
            result.push_back(it.second);
        }

        return result;
    }
};