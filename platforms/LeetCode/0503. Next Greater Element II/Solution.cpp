#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int GreaterNum = -1;
            bool gotGreaterNum = false;
            int j;
            for (j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    GreaterNum = nums[j];
                    gotGreaterNum = true;
                    break;
                }
            }
            j = 0;
            while (!gotGreaterNum && j < i)
            {
                if (nums[j] > nums[i])
                {
                    GreaterNum = nums[j];
                    gotGreaterNum = true;
                    break;
                }
                j++;
            }
            ans.push_back(GreaterNum);
        }
        return ans;
    }
};