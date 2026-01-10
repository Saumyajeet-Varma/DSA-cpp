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
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL || head->next == nullptr)
            return head;
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL)
        {
            if (slow->data != fast->data)
            {
                slow = slow->next;
                int temp = slow->data;
                slow->data = fast->data;
                fast->data = temp;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};