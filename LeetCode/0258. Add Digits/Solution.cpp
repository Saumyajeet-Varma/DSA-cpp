#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        int ans = 0;
        int temp = num;
        while (temp / 10 > 0)
        {
            while (temp > 0)
            {
                ans += temp % 10;
                temp /= 10;
            }
            temp = ans;
            ans = 0;
        }
        ans = temp;
        return ans;
    }
};