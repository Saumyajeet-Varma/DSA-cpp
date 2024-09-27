#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool selfDivide(int num)
    {
        int temp = num;
        while (temp > 0)
        {
            int digit = temp % 10;
            if (digit == 0)
                return false;
            if (num % digit != 0)
                return false;
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (selfDivide(i))
                ans.push_back(i);
        }
        return ans;
    }
};