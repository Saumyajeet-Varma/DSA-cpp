class Solution
{
public:
    int sum(int num1, int num2)
    {
        if (num1 == 0)
            return num2;
        if (num2 == 0)
            return num1;
        while (num2 != 0)
        {
            int carry = num1 & num2;
            num1 = num1 ^ num2;
            num2 = carry << 1;
        }
        return num1;
    }
};