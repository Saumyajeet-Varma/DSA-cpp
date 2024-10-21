#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int start, string &s, unordered_set<string> &st)
    {
        int n = s.length();
        if (start == n)
            return 0;
        int maxSplits = 0;
        for (int i = start + 1; i <= n; i++)
        {
            string subStr = s.substr(start, i - start);
            if (st.find(subStr) == st.end())
            {
                st.insert(subStr);
                maxSplits = max(maxSplits, 1 + dfs(i, s, st));
                st.erase(subStr);
            }
        }
        return maxSplits;
    }

    // Main Function
    int maxUniqueSplit(string s)
    {
        unordered_set<string> st;
        return dfs(0, s, st);
    }
};