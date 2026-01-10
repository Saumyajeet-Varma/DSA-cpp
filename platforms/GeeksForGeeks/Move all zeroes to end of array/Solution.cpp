class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }
    }
};