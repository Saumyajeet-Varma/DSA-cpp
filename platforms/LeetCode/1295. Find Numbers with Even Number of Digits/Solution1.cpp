#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countDigits(int num)
    {
        int count = 0;

        while (num > 0)
        {
            num /= 10;
            count++;
        }

        return count;
    }

public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int num : nums)
        {
            if (countDigits(num) % 2 == 0)
                count++;
        }

        return count;
    }
};