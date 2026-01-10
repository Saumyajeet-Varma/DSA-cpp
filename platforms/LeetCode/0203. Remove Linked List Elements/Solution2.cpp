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
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *temp = dummyHead;
        while (temp->next != NULL)
        {
            if (temp->next->val == val)
            {
                if (temp->next->next == nullptr)
                {
                    temp->next = nullptr;
                    break;
                }
                temp->next = temp->next->next;
            }
            else
                temp = temp->next;
        }
        return dummyHead->next;
    }
};