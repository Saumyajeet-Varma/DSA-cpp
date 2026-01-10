#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int newSize = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[newSize] = nums[i];
                newSize++;
            }
        }
        return newSize;
    }
};