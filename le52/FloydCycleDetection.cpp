#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Insert(Node *&tail, int element)
{
    Node *newNode = new Node(element);
    tail->next = newNode;
    tail = newNode;
}

bool CycleDetection(Node *head)
{
    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == false)
        {
            visited[temp] = true;
            temp = temp->next;
        }
        else
        {
            return true;
        }
    }

    return false;
}

Node *floydDetection(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {

            fast = fast->next;
        }

        slow = slow->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *intersection = floydDetection(head);
    Node *slow = head;
    while (slow->next != intersection->next)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    // return slow->next;
    return intersection;
}

void removeLoops(Node *&head)
{
    Node *toChange = getStartingNode(head);

    toChange->next = NULL;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    Insert(tail, 5);
    Insert(tail, 1);
    Insert(tail, 7);
    Insert(tail, 8);
    tail->next = head->next; // making the single linked list into the circular one
    // tail->next = head; // making the single linked list into the circular one  for   list having only one element
    // print(head);
    // cout << CycleDetection(head) << endl;
    bool val = floydDetection(head) == NULL ? false : true;
    cout << val << endl;
    cout << "Starting Node of the circular list " << getStartingNode(head)->next->data << endl;
    removeLoops(head); // by the Internal loop has been removed
    print(head);
    return 0;
}