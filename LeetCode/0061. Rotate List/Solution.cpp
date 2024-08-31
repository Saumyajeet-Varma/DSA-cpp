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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == nullptr || k == 0)
            return head;
        ListNode *tail = head;
        int len = 1;
        while (tail->next != nullptr)
        {
            len++;
            tail = tail->next;
        }
        ListNode *temp = head;
        int move = 1;
        k = k % len;
        while (move < len - k)
        {
            temp = temp->next;
            move++;
        }
        tail->next = head;
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
