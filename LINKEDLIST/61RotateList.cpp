// approach 1-- using map

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == nullptr)
            return head;

        int len = 0;
        unordered_map<ListNode *, ListNode *> mp;

        ListNode *temp = head;
        ListNode *prev = nullptr;
        while (temp->next != nullptr)
        {
            len++;
            mp[temp] = prev;
            prev = temp;
            temp = temp->next;
        }
        mp[temp] = prev;
        len++;

        ListNode *last = temp;

        k = k % len;

        while (k--)
        {
            ListNode *prevElement = mp[last];
            prevElement->next = nullptr;
            mp[last] = nullptr;
            mp[head] = last;
            last->next = head;
            head = last;
            last = prevElement;
        }

        return head;
    }
};

/// approach 2-- most optimal

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == nullptr)
            return head;

        int len = 0;

        ListNode *temp = head;

        while (temp->next != nullptr)
        {
            len++;

            temp = temp->next;
        }

        len++;

        ListNode *last = temp;

        k = k % len;
        if (k == 0)
            return head;
        k = len - k - 1;
        temp = head;
        while (k--)
        {
            temp = temp->next;
        }

        ListNode *next = temp->next;
        temp->next = nullptr;
        last->next = head;
        head = next;

        return head;
    }
};