#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int n = pattern.size();

        string result = "";
        vector<int> vec(n + 1);
        int index = 0;

        for (int i = 0; i <= n; i++)
        {
            vec[index] = i + 1;
            index++;

            if (i == n || pattern[i] == 'I')
            {
                while (index > 0)
                {
                    index--;
                    result += to_string(vec[index]);
                }
            }
        }

        return result;
    }
};