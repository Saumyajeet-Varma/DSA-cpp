#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int k = unordered_set<int>(nums.begin(), nums.end()).size();

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;

            for (int j = i; j < n; j++)
            {
                st.insert(nums[j]);

                if (st.size() == k)
                    count++;
            }
        }

        return count;
    }
};