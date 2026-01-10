class Solution
{
public:
    int sum(int num1, int num2)
    {
        return num2 == 0 ? num1 : sum(num1 ^ num2, (num1 & num2) << 1);
    }
};
