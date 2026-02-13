class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *odd = head;        // first odd node
        ListNode *even = head->next; // first even node
        ListNode *evenHead = even;   // save start of even list

        while (even && even->next)
        {
            odd->next = even->next; // link next odd
            odd = odd->next;

            even->next = odd->next; // link next even
            even = even->next;
        }

        odd->next = evenHead; // attach even list after odds

        return head;
    }
};
