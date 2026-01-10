#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp = temp ^ nums[i];
        }
        return temp;
    }
};