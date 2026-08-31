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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int starting = -1;
        int prev = -1;
        int prevVal = -1;
        ListNode *temp = head;
        int i = 1;

        int mini = INT_MAX;

        while (temp && temp->next)
        {
            int value = temp->val;
            int nxtValue = temp->next->val;
            if (prevVal != -1 && temp->next &&
                ((prevVal < value && value > nxtValue) ||
                 (prevVal > value && value < nxtValue)))
            {
                if (prev == -1)
                {
                    starting = i;
                }
                else
                {

                    mini = min(mini, abs(prev - i));
                }

                prev = i;
            }

            i++;
            prevVal = temp->val;

            temp = temp->next;
        }

        return (starting == -1 || prev == starting)
                   ? vector<int>{-1, -1}
                   : vector<int>{mini, prev - starting};
    }
};