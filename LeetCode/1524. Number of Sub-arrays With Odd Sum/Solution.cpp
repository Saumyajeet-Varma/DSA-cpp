#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1000000007;

public:
    int numOfSubarrays(vector<int> &arr)
    {
        int n = arr.size();

        int odd = 0;
        int even = 0;

        long long sum = 0;
        long long result = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum % 2 == 1)
            {
                odd++;
                result += even + 1;
            }
            else
            {
                even++;
                result += odd;
            }
        }

        return result % MOD;
    }
};