
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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *list2 = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr;

        while (list2)
        {
            ListNode *temp = list2->next;
            list2->next = prev;

            prev = list2;
            list2 = temp;
        }

        ListNode *list1 = head;
        list2 = prev;

        while (list2)
        {
            ListNode *next1 = list1->next;
            ListNode *next2 = list2->next;

            list1->next = list2;
            list2->next = next1;

            list1 = next1;
            list2 = next2;
        }
    }
};