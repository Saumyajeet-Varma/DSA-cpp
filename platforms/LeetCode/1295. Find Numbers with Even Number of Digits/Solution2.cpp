#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int num : nums)
        {
            string numStr = to_string(num);

            if (numStr.size() % 2 == 0)
                count++;
        }

        return count;
    }
};