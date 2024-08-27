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
    Node *findMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *mergeLL(Node *list1, Node *list2)
    {
        Node *dummyHead = new Node(0);
        Node *temp = dummyHead;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->data < list2->data)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            temp->next = list1;
        else
            temp->next = list2;
        return dummyHead->next;
    }

    Node *segregate(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *middleNode = findMiddle(head);
        Node *leftHead = head;
        Node *rightHead = middleNode->next;
        middleNode->next = nullptr;
        leftHead = segregate(leftHead);
        rightHead = segregate(rightHead);
        return mergeLL(leftHead, rightHead);
    }
};