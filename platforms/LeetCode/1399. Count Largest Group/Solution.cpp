#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int digitSum(int n)
    {
        int sum = 0;

        while (n)
        {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

public:
    int countLargestGroup(int n)
    {
        vector<int> sums(37); // max value of n is 10000 [Given in the constraints], max sum value: 9+9+9+9=36

        for (int i = 1; i <= n; i++)
        {
            sums[digitSum(i)]++;
        }

        int maxx = 0;
        int count = 0;

        for (int sum : sums)
        {
            if (sum > maxx)
            {
                maxx = sum;
                count = 1;
            }
            else if (sum == maxx)
            {
                count++;
            }
        }

        return count;
    }
};