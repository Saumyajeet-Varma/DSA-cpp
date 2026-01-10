class Solution
{
public:
    long long coloredCells(int n)
    {
        long long count = 1;

        n--;

        while (n)
        {
            count += n * 4;
            n--;
        }

        return count;
    }
};