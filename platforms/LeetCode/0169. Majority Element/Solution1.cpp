#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int key, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                key = nums[i];
            }
            if (key == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return key;
    }
};