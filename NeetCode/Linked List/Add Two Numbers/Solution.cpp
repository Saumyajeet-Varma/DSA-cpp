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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        int carry = 0;

        while (l1 || l2 || carry)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int val = val1 + val2 + carry;

            carry = val / 10;
            val = val % 10;

            curr->next = new ListNode(val);

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;

            curr = curr->next;
        }

        return dummy->next;
    }
};
