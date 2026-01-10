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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
            return true;
        stack<int> stk;
        ListNode *temp = head;
        while (temp != NULL)
        {
            stk.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (temp->val == stk.top())
                stk.pop();
            temp = temp->next;
        }
        return stk.empty();
    }
};