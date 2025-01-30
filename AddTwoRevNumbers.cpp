/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *sumTail = NULL;
        ListNode *sumHead = NULL;

        while (l1 != NULL && l2 != NULL)
        {
            int n = l1->val + l2->val + carry;

            int x = n % 10;
            if (sumTail == NULL)
            {
                sumTail = new ListNode(x);
                sumHead = sumTail;
            }
            else
            {
                sumTail->next = new ListNode(x);
                sumTail = sumTail->next;
            }

            carry = n / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            int n = carry + l1->val;
            int x = n % 10;
            sumTail->next = new ListNode(x);
            sumTail = sumTail->next;

            carry = n / 10;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            int n = carry + l2->val;
            int x = n % 10;
            sumTail->next = new ListNode(x);
            sumTail = sumTail->next;
            carry = n / 10;
            l2 = l2->next;
        }

        if (carry != 0)
        {
            sumTail->next = new ListNode(carry);
            sumTail = sumTail->next;
        }
        return sumHead;
    }
};