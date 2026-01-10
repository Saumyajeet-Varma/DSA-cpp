#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1000000007;

    int countDistinct(int num)
    {
        int count = 0;

        if (num % 2 == 0)
        {
            count++;

            while (num % 2 == 0)
            {
                num /= 2;
            }
        }

        for (long long i = 3; i * i <= num; i += 2)
        {
            if (num % i == 0)
            {
                count++;

                while (num % i == 0)
                {
                    num /= i;
                }
            }
        }

        if (num > 2)
            count++;

        return count;
    }

    int modPow(int base, int exp)
    {
        long long result = 1;
        long long b = base % MOD;

        while (exp > 0)
        {
            if (exp & 1)
                result = (result * b) % MOD;

            b = (b * b) % MOD;
            exp = exp >> 1;
        }

        return (int)result;
    }

public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (n == 0)
            return 1;

        priority_queue<pair<int, int>> maxValues;
        vector<int> rightMax(n, n);
        vector<int> leftMax(n, -1);
        vector<int> primeScores(n, 0);
        stack<int> stk;
        stack<int> rev;

        for (int i = 0; i < n; i++)
        {
            primeScores[i] = countDistinct(nums[i]);
            maxValues.push({nums[i], i});
        }

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && primeScores[i] > primeScores[stk.top()])
            {
                rightMax[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!rev.empty() && primeScores[i] >= primeScores[rev.top()])
            {
                leftMax[rev.top()] = i;
                rev.pop();
            }

            rev.push(i);
        }

        int result = 1;

        while (!maxValues.empty() && k > 0)
        {
            auto topp = maxValues.top();
            maxValues.pop();

            int val = topp.first;
            int idx = topp.second;

            long long c = 1LL * (rightMax[idx] - idx) * (idx - leftMax[idx]);
            long long steps = min(c, (long long)k);
            int multiply = modPow(val, (int)steps);

            result = (int)((1LL * result * multiply) % MOD);

            k -= steps;
        }

        return result % MOD;
    }
};