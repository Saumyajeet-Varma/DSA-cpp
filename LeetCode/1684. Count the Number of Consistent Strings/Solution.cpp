#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_set<char> st;
        for (char i : allowed)
        {
            st.insert(i);
        }
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string str = words[i];
            bool val = true;
            for (char j : str)
            {
                if (st.find(j) == st.end())
                {
                    val = false;
                }
            }
            if (val)
                count++;
        }
        return count++;
    }
};