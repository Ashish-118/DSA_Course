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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }

        ListNode *prev = nullptr;

        if (len == n)
        {
            ListNode *temp2 = head->next;
            delete head;
            return temp2;
        }

        temp = head;

        while (temp != nullptr)
        {
            if (len == n)
            {
                if (temp->next == nullptr)
                {
                    prev->next = nullptr;
                }

                prev->next = temp->next;
                delete temp;
                break;
            }
            len--;
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

// using 1 pass approach

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            return head->next;
        }

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete (temp);
        return head;
    }
};