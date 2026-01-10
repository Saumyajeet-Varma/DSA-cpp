#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();

        int eq = 0;
        vector<int> vec1;
        vector<int> vec2;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
                vec1.push_back(nums[i]);
            else if (nums[i] > pivot)
                vec2.push_back(nums[i]);
            else
                eq++;
        }

        while (eq)
        {
            vec1.push_back(pivot);
            eq--;
        }

        for (int el : vec2)
        {
            vec1.push_back(el);
        }

        return vec1;
    }
};