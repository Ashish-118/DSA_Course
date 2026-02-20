/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *temp = headA;
        int l1 = 0, l2 = 0;

        while (temp != NULL)
        {
            l1++;

            temp = temp->next;
        }

        temp = headB;

        while (temp != NULL)
        {
            l2++;

            temp = temp->next;
        }

        int diff = l1 - l2;

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        if (diff < 0)
        {
            for (int i = 0; i < abs(diff); i++)
            {
                tempB = tempB->next;
            }
        }
        else
        {
            for (int i = 0; i < diff; i++)
            {
                tempA = tempA->next;
            }
        }

        while (tempA != NULL && tempB != NULL)
        {
            if (tempA == tempB)
                return tempA;
            else
            {
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }

        return NULL;
    }
};