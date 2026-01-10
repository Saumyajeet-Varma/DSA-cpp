class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n <= 0)
            return false;

        while (n)
        {
            int q = n / 3;
            int r = n % 3;

            if (r == 2)
                return false;

            n = q;
        }

        return true;
    }
};