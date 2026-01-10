#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int maxx = 0;
        int depth = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                depth++;
                maxx = max(maxx, depth);
            }
            else if (ch == ')')
            {
                depth--;
            }
        }
        return maxx;
    }
};