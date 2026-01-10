#include <bits/stdc++.h>
using namespace std;

// This algorithm doesn't satisfy the time ans space complexity contraints.
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        vector<string> ansStr;
        for (int i = 1; i <= n; i++)
        {
            ansStr.push_back(to_string(i));
        }
        sort(ansStr.begin(), ansStr.end());
        for (auto i : ansStr)
        {
            ans.push_back(stoi(i));
        }
        return ans;
    }
};