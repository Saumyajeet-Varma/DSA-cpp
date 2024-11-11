#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sieveOfEratosthenes(vector<int> &primes, int maxVal)
    {
        vector<bool> sieve(maxVal + 1, false);
        for (int i = 2; i * i < maxVal; i++)
        {
            if (sieve[i] == false)
            {
                for (int j = 2; i * j < maxVal; j++)
                {
                    sieve[i * j] = true;
                }
            }
        }
        for (int i = 2; i < maxVal; i++)
        {
            if (sieve[i] == false)
                primes.push_back(i);
        }
    }

    bool primeSubOperation(vector<int> &nums)
    {
        vector<int> primes;
        int maxVal = *max_element(nums.begin(), nums.end());
        sieveOfEratosthenes(primes, maxVal);
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int diff = i == 0 ? nums[0] - 1 : nums[i] - nums[i - 1] - 1;
            int lb = lower_bound(primes.begin(), primes.end(), diff) - primes.begin();
            if (lb == primes.size() || primes[lb] > diff)
                lb--;
            if (lb < 0)
            {
                if (i == 0 || nums[i] > nums[i - 1])
                    continue;
                else
                    return false;
            }
            nums[i] -= primes[lb];
        }
        return true;
    }
};