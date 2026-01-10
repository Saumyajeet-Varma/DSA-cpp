#include <bits/stdc++.h>
using namespace std;

struct MinHeap
{
private:
    int *heap;
    int capacity;
    int heap_size;

public:
    MinHeap(int c)
    {
        heap_size = 0;
        capacity = c;
        heap = new int[c];
    }

    ~MinHeap()
    {
        delete[] heap;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i)
    {
        return (2 * i) + 1;
    }

    int right(int i)
    {
        return (2 * i) + 2;
    }

    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap_size && heap[r] < heap[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return -1;
        int minn = heap[0];
        heap_size--;
        heap[0] = heap[heap_size];
        if (heap_size > 0)
            heapify(0);
        return minn;
    }

    void decreaseKey(int i, int newVal)
    {
        heap[i] = newVal;
        while (i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void insertKey(int val)
    {
        if (heap_size == capacity)
            return;
        heap_size++;
        decreaseKey(heap_size - 1, val);
    }

    void deleteKey(int i)
    {
        if (i >= heap_size)
            return;
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};