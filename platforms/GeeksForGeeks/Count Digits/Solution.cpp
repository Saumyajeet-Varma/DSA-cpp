class Solution
{
public:
    int evenlyDivides(int N)
    {
        int count = 0;
        int temp = N;
        while (temp > 0)
        {
            int digit = temp % 10;
            if (digit != 0)
            {
                if (N % digit == 0)
                {
                    count++;
                }
            }
            temp = temp / 10;
        }
        return count;
    }
};