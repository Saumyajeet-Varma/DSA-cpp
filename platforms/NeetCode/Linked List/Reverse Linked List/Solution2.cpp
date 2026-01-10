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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        stack<int> stk;

        ListNode *mover = head;

        while (mover)
        {
            stk.push(mover->val);
            mover = mover->next;
        }

        mover = head;

        while (mover)
        {
            mover->val = stk.top();
            stk.pop();
            mover = mover->next;
        }

        return head;
    }
};
