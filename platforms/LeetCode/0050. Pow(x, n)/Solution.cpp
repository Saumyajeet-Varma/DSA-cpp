class Solution
{
public:
    double myPow(double x, int n)
    {
        long long ln = n;
        if (ln == 0)
            return 1;
        if (ln < 0)
        {
            x = 1 / x;
            ln = -ln;
        }
        double ans = 1;
        while (ln)
        {
            if (ln % 2 == 0)
            {
                x = x * x;
                ln = ln / 2;
            }
            else
            {
                ans = ans * x;
                ln--;
            }
        }
        return ans;
    }
};