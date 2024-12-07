class Solution
{
public:
    bool isPossible(int a, int b)
    {
        if (a == b)
            return 0;
        if (a + b == 4)
            return 0;
        return 1;
    }
};