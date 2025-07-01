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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || !head->next || left == right)
            return head;

        int count = 1;
        ListNode *curr = head;
        stack<int> stk;

        while (count <= right)
        {
            if (count >= left)
                stk.push(curr->val);

            curr = curr->next;
            count++;
        }

        count = 1;
        curr = head;

        while (count <= right)
        {
            if (count >= left)
            {
                curr->val = stk.top();
                stk.pop();
            }

            curr = curr->next;
            count++;
        }

        return head;
    }
};