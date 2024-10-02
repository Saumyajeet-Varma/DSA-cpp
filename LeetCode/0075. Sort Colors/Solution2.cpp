#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }
        int i = 0;
        while (i < freq[0])
        {
            nums[i] = 0;
            i++;
        }
        while (i < freq[0] + freq[1])
        {
            nums[i] = 1;
            i++;
        }
        while (i < freq[0] + freq[1] + freq[2])
        {
            nums[i] = 2;
            i++;
        }
    }
};