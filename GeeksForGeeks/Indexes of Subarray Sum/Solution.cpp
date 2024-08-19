#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        vector<int> ans;
        int left = 0, right = 0;
        long long sum = 0;
        while (right < n)
        {
            sum += arr[right];
            while (sum > s && left < right)
            {
                sum -= arr[left];
                left++;
            }
            if (sum == s)
            {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            }
            right++;
        }
        ans.push_back(-1);
        return ans;
    }
};