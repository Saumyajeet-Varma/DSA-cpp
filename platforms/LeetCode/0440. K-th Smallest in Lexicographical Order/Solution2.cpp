#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceed
class Solution
{
public:
    int findKthNumber(int n, int k)
    {
        vector<string> lexStr;
        for (int i = 1; i <= n; i++)
        {
            lexStr.push_back(to_string(i));
        }
        sort(lexStr.begin(), lexStr.end());
        return stoi(lexStr[k - 1]);
    }
};