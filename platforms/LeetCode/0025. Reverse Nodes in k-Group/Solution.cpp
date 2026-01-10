#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        if (head == NULL || head->next == nullptr)
            return head;
        ListNode *temp = head;
        ListNode *prevNode = NULL;
        while (temp != NULL)
        {
            ListNode *nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }
        return prevNode;
    }

    ListNode *findKthNode(ListNode *head, int k)
    {
        k -= 1;
        while (head != NULL && k > 0)
        {
            k--;
            head = head->next;
        }
        return head;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *nextNode = NULL;
        ListNode *prevNode = NULL;
        while (temp != NULL)
        {
            ListNode *kthNode = findKthNode(temp, k);
            if (kthNode == NULL)
            {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if (temp == head)
                head = kthNode;
            else
                prevNode->next = kthNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};