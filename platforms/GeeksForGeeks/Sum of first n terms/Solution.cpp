class Solution
{
public:
    long long sumOfSeries(long long n)
    {
        long long sum = (n) * (n + 1) / 2;
        long long cube = sum * sum;
        return cube;
    }
};