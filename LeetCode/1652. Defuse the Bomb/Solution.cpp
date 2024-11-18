#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;
        if (k > 0)
        {
            int sum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            ans[0] = sum;
            int l = 1, r = k + 1;
            while (l < n)
            {
                sum += -code[l] + code[r % n];
                ans[l] = sum;
                l++;
                r++;
            }
            return ans;
        }
        k = -k;
        int sum = accumulate(code.end() - k, code.end(), 0);
        ans[0] = sum;
        int r = 0, l = n - k;
        while (r < n - 1)
        {
            sum += -code[l % n] + code[r];
            ans[r + 1] = sum;
            l++;
            r++;
        }
        return ans;
    }
};