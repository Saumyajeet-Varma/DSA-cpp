#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int maxlen = 0;
        set<long long> st;
        for (int num : nums)
        {
            st.insert(num);
        }
        for (long long num : st)
        {
            int len = 0;
            long long curr = num;
            while (st.find(curr) != st.end())
            {
                len++;
                if (curr > 100000)
                    break;
                curr = curr * curr;
            }
            if (len > 1)
                maxlen = max(maxlen, len);
        }
        return maxlen > 1 ? maxlen : -1;
    }
};