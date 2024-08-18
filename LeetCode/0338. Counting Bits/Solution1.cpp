#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            int temp = i;
            while (temp)
            {
                count++;
                temp = (temp & (temp - 1));
            }
            ans.push_back(count);
        }
        return ans;
    }
};