#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int digitSum(int num)
    {
        int temp = num;
        int sum = 0;
        while (temp > 0)
        {
            int rem = temp % 10;
            sum += rem;
            temp = temp / 10;
        }
        return sum;
    }

    int getLucky(string s, int k)
    {
        unordered_map<char, int> mpp;
        mpp['a'] = 1,
        mpp['b'] = 2,
        mpp['c'] = 3,
        mpp['d'] = 4,
        mpp['e'] = 5,
        mpp['f'] = 6,
        mpp['g'] = 7,
        mpp['h'] = 8,
        mpp['i'] = 9,
        mpp['j'] = 10,
        mpp['k'] = 11,
        mpp['l'] = 12,
        mpp['m'] = 13,
        mpp['n'] = 14,
        mpp['o'] = 15,
        mpp['p'] = 16,
        mpp['q'] = 17,
        mpp['r'] = 18,
        mpp['s'] = 19,
        mpp['t'] = 20,
        mpp['u'] = 21,
        mpp['v'] = 22,
        mpp['w'] = 23,
        mpp['x'] = 24,
        mpp['y'] = 25,
        mpp['z'] = 26;
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += digitSum(mpp[s[i]]);
        }
        k -= 1;
        while (k > 0)
        {
            sum = digitSum(sum);
            k--;
        }
        return sum;
    }
};