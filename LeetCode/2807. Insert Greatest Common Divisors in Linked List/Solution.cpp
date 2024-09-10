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
    int GCD(int num1, int num2)
    {
        int minNum = min(num1, num2);
        for (int i = minNum; i >= 1; i--)
        {
            if (num1 % i == 0 && num2 % i == 0)
                return i;
        }
        return 1;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head == NULL || head->next == nullptr)
            return head;
        ListNode *curr = head;
        ListNode *nextNode = head->next;
        while (nextNode)
        {
            int gcd = GCD(curr->val, nextNode->val);
            ListNode *newNode = new ListNode(gcd);
            curr->next = newNode;
            newNode->next = nextNode;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};