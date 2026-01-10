#include <bits/stdc++.h>
using namespace std;

// ! Time Limit Exceed
class KthLargest
{
private:
    int k;
    vector<int> nums;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        this->nums = nums;
    }

    int add(int val)
    {
        nums.push_back(val);
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */