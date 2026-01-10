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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return head;
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
        ListNode *temp = head;
        ListNode *prevNode = NULL;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                prevNode->next = temp->next;
                temp = temp->next;
            }
            else
            {
                prevNode = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};