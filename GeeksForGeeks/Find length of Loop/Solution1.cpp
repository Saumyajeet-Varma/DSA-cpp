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
    int loopLen(Node *slow, Node *fast)
    {
        int len = 1;
        slow = fast->next;
        while (slow != fast)
        {
            len++;
            slow = slow->next;
        }
        return len;
    }

    int countNodesinLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return loopLen(slow, fast);
        }
        return 0;
    }
};