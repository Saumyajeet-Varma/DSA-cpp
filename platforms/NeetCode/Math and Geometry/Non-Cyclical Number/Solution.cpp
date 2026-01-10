class Solution
{
private:
    int digitSquareSum(int n)
    {
        int sum = 0;

        while (n)
        {
            int rem = n % 10;
            sum += (rem * rem);
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }

        int slow = digitSquareSum(n);
        int fast = digitSquareSum(digitSquareSum(n));

        if (slow == 1 || fast == 1)
        {
            return true;
        }

        while (slow != fast)
        {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));

            if (slow == 1 || fast == 1)
            {
                return true;
            }
        }

        return false;
    }
};
