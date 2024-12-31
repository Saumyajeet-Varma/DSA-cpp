#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void heapify(vector<int> &arr, int i, int N)
    {
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        int largest = i;
        if (left < N && arr[left] > arr[largest])
            largest = left;
        if (right < N && arr[right] > arr[largest])
            largest = right;
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, largest, N);
        }
    }

public:
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        for (int i = (N / 2) - 1; i >= 0; i--)
        {
            heapify(arr, i, N);
        }
    }
};