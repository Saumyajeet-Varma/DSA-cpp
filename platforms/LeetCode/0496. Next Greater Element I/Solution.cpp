#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> mpp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n2; i++)
        {
            mpp[nums2[i]] = i + 1;
        }
        for (int i = 0; i < n1; i++)
        {
            int greaterNum = -1;
            if (mpp[nums1[i]])
            {
                for (int j = mpp[nums1[i]]; j < n2; j++)
                {
                    if (nums2[j] > nums1[i])
                    {
                        greaterNum = nums2[j];
                        break;
                    }
                }
                ans.push_back(greaterNum);
            }
        }
        return ans;
    }
};