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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *mover = dummyHead;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                ListNode *newNode = new ListNode(list1->val);
                mover->next = newNode;
                mover = mover->next;
                list1 = list1->next;
            }
            else
            {
                ListNode *newNode = new ListNode(list2->val);
                mover->next = newNode;
                mover = mover->next;
                list2 = list2->next;
            }
        }

        if (list1)
        {
            mover->next = list1;
        }

        if (list2)
        {
            mover->next = list2;
        }

        return dummyHead->next;
    }
};
