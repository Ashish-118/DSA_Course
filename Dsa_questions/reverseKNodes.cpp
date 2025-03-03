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
    int len(ListNode *head)
    {
        int c = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *temp2 = NULL;
        int n = len(head) / k;
        bool once = true;
        while (n--)
        {
            ListNode *current = temp;
            ListNode *firstNode = current;
            ListNode *forward = NULL;
            ListNode *prev = NULL;

            int count = k;
            while (count--)
            {
                forward = current->next;
                current->next = prev;
                prev = current;
                current = forward;
            }

            if (once)
            {
                head = prev;
                temp2 = temp;
                once = !once;
            }
            else
            {
                temp2->next = prev;
                temp2 = temp;
            }
            temp = prev;
            firstNode->next = current;
            temp = firstNode->next;
        }
        return head;
    }
};