class Solution
{
public:
    void sort012(int a[], int n)
    {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {
            switch (a[i])
            {
            case 0:
                count0++;
                break;
            case 1:
                count1++;
                break;
            default:
                count2++;
            }
        }
        for (int i = 0; i < count0; i++)
        {
            a[i] = 0;
        }
        for (int i = count0; i < count0 + count1; i++)
        {
            a[i] = 1;
        }
        for (int i = count0 + count1; i < n; i++)
        {
            a[i] = 2;
        }
    }
};