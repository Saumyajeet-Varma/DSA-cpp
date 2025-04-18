#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string curr = "1";

        if (n == 1)
            return curr;

        for (int i = 2; i <= n; i++)
        {
            int count = 1;
            int c = curr.length();
            char ch = curr[0];
            string next = "";

            for (int j = 1; j < c; j++)
            {
                if (curr[j] == ch)
                {
                    count++;
                }
                else
                {
                    next += to_string(count) + ch;
                    ch = curr[j];
                    count = 1;
                }
            }

            next += to_string(count) + ch;
            curr = next;
        }

        return curr;
    }
};