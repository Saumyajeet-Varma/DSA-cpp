#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canChange(string start, string target)
    {
        int n = start.length();
        for (int i = 0, j = 0; i < n || j < n; i++, j++)
        {
            while (i < n && start[i] == '_')
            {
                i++;
            }
            while (j < n && target[j] == '_')
            {
                j++;
            }
            char ch = start[i];
            if (ch != target[j])
                return false;
            if (ch == 'L' && i < j)
                return false;
            if (ch == 'R' && i > j)
                return false;
        }
        return true;
    }
};