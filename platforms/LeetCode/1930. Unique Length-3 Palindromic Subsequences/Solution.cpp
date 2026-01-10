#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
        vector<int> left(26, -1);
        vector<int> right(26, -1);
        for (int i = 0; i < n; i++)
        {
            if (left[s[i] - 'a'] == -1)
                left[s[i] - 'a'] = i;
            right[s[i] - 'a'] = i;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (left[i] != -1 && right[i] != -1)
            {
                unordered_set<int> st;
                for (int j = left[i] + 1; j < right[i]; j++)
                {
                    st.insert(s[j]);
                }
                count += st.size();
            }
        }
        return count;
    }
};