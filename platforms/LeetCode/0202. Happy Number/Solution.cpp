class Solution
{
public:
    int squareDigitSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += (digit * digit);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = squareDigitSum(n);
        int fast = squareDigitSum(squareDigitSum(n));
        while ((slow != fast) && (slow != 1))
        {
            slow = squareDigitSum(slow);
            fast = squareDigitSum(squareDigitSum(fast));
        }
        return slow == 1;
    }
};