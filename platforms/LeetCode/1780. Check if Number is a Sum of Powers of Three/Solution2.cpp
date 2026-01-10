class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n <= 0)
            return false;

        if (n % 3 == 2)
            return false;

        if (n < 3)
            return true;

        return checkPowersOfThree(n / 3);
    }
};