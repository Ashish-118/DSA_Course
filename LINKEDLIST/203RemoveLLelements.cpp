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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *prev = nullptr;
        ListNode *temp = head;

        while (temp)
        {
            if (temp->val == val)
            {
                if (!prev)
                {
                    ListNode *toDelete = temp;
                    head = temp->next;
                    temp = head;
                    delete (toDelete);
                }
                else
                {
                    ListNode *toDelete = temp;

                    prev->next = temp->next;
                    temp = temp->next;
                    delete toDelete;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};