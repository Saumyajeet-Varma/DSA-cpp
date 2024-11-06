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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *prev = head;
        ListNode *curr = prev->next;
        while (curr)
        {
            if (curr->val == prev->val)
            {
                curr = curr->next;
            }
            else
            {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        prev->next = nullptr;
        return head;
    }
};