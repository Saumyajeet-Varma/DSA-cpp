#include <bits/stdc++.h>
using namespace std;

int H[10009];
int s = -1;

int leftChild(int i)
{
    return (2 * i) + 1;
}

int rightChild(int i)
{
    return (2 * i) + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i])
    {
        swap(H[i], H[parent(i)]);
        i = parent(i);
    }
}

void shiftDown(int i)
{
    int maxIndex = i;
    int left = leftChild(i);
    int right = rightChild(i);
    if (left <= s && H[left] > H[maxIndex])
    {
        maxIndex = H[left];
    }
    if (right <= s && H[right] > H[maxIndex])
    {
        maxIndex = H[right];
    }
    if (i != maxIndex)
    {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int data)
{
    s++;
    H[s] = data;
    shiftUp(s);
}

// 01. parent(i): Function to return the parent node of node i
// 02. leftChild(i): Function to return index of the left child of node i
// 03. rightChild(i): Function to return index of the right child of node i
// 04. shiftUp(int i): Function to shift up the node in order to maintain the heap property
// 05. shiftDown(int i): Function to shift down the node in order to maintain the heap property.

// int s=-1, current index value of the array H[].

class Solution
{
public:
    int extractMax()
    {
        int maxx = H[0];
        swap(H[0], H[s]);
        s--;
        shiftDown(0);
        return maxx;
    }
};