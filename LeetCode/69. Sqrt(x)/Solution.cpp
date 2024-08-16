class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
            return x;

        long ans = 0;
        long left = 1;
        long right = x / 2;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};