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
        ListNode *temp = head;
        int len = 1;
        while (temp->next != nullptr)
        {
            len++;
            temp = temp->next;
        }
        ListNode *tail = head;
        int move = 1;
        k = k % len;
        while (move < len - k)
        {
            tail = tail->next;
            move++;
        }
        temp->next = head;
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};