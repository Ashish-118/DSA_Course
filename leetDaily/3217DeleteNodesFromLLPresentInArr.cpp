class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]] = true;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {

            if (freq[curr->val])
            {

                if (head == curr)
                {

                    head = head->next;
                    curr = head;
                }
                else
                {
                    prev->next = curr->next;
                    ListNode *del = curr;

                    curr = curr->next;
                    delete del;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};