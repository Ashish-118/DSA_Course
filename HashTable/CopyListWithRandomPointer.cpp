

class Solution
{
public:
    unordered_map<Node *, pair<Node *, Node *>> mp;
    Node *copyRandomList(Node *head)
    {

        Node *temp = head;
        Node *deepCopyHead = NULL;

        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            mp[temp] = {newNode, temp->random};
            if (temp == head)
            {
                deepCopyHead = newNode;
            }

            temp = temp->next;
        }

        for (auto x : mp)
        {
            Node *newNode = x.second.first;
            Node *originalNode = x.first;
            Node *random = x.second.second;

            newNode->next =
                (!originalNode->next ? NULL : mp[originalNode->next].first);
            newNode->random = (!random ? NULL : mp[random].first);
        }

        return deepCopyHead;
    }
};