#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *segregate(Node *head)
    {
        unordered_map<int, int> mpp;
        Node *temp = head;
        while (temp != NULL)
        {
            mpp[temp->data]++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < mpp[0]; i++)
        {
            temp->data = 0;
            temp = temp->next;
        }
        for (int i = 0; i < mpp[1]; i++)
        {
            temp->data = 1;
            temp = temp->next;
        }
        for (int i = 0; i < mpp[2]; i++)
        {
            temp->data = 2;
            temp = temp->next;
        }
        return head;
    }
};