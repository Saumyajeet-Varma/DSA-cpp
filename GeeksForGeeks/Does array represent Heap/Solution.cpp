class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            int left = (2 * i) + 1;
            int right = (2 * i) + 2;
            if (arr[i] < arr[left] || arr[i] < arr[right])
                return false;
        }
        return true;
    }
};