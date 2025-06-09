class Solution
{
public:
    int nthFibonacci(int n)
    {
        if (n == 0 || n == 1)
            return n;

        int result;

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; i++)
        {
            result = prev2 + prev1;
            prev2 = prev1;
            prev1 = result;
        }

        return result;
    }
};