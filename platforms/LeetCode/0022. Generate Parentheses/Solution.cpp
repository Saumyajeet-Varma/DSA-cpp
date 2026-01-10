#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void recursiveFunc(int open, int close, string str, int n, vector<string> &result)
    {
        if (open == close && open == n)
        {
            result.push_back(str);
            return;
        }

        if (open < n)
            recursiveFunc(open + 1, close, str + "(", n, result);

        if (close < open)
            recursiveFunc(open, close + 1, str + ")", n, result);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        recursiveFunc(0, 0, "", n, result);
        return result;
    }
};