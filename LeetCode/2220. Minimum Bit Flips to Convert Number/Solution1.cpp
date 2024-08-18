class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int bits = start ^ goal;
        int flip = 0;
        while (bits)
        {
            flip++;
            bits = (bits & (bits - 1));
        }
        return flip;
    }
};