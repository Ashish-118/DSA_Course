/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *solve(Node *head)
    {
        Node *temp = head;
        Node *tail = head;

        while (temp)
        {
            Node *nextNode = temp->next;

            // If a child exists
            if (temp->child)
            {
                Node *childTail = solve(temp->child);

                // Connect temp and child
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;

                // Connect childTail and nextNode
                if (nextNode)
                {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                tail = childTail; // update tail
            }
            else
            {
                tail = temp;
            }

            temp = nextNode;
        }

        return tail;
    }

    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        solve(head);
        return head;
    }
};
