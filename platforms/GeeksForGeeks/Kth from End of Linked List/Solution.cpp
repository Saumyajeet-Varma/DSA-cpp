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
    int getKthFromLast(Node *head, int k)
    {
        Node *fast = head;
        Node *slow = head;
        while (k > 1)
        {
            fast = fast->next;
            k--;
            if (fast == NULL)
                return -1;
        }
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->data;
    }
};