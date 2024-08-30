#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int getMiddle(Node *head)
    {
        if (head == NULL)
            return -1;
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};