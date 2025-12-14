#include <iostream>
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

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Destructor is called and deleted the element" << endl;
    }
};

void insertAthead(Node *&head, int d)
{
    // New node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insert(Node *&tail, Node *&head, int pos, int element)
{
    if (pos == 1)
    {
        insertAthead(head, element);
        return;
    }

    // inserting at Last Position

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {

        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, element);
        return;
    }
    // creating a node for d
    Node *nodeToInsert = new Node(element);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deletion(Node *&tail, Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        int cnt = 1;
        Node *prev = head;
        Node *curr = head;

        while (cnt <= pos - 1)
        {
            if (cnt <= (pos - 2))
            {
                prev = prev->next;
            }

            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
            prev->next = curr->next;
            // curr->next = NULL;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}
int main()
{
    // created a New Node
    Node *node1 = new Node(10);
    // cout << node1->data << " " << node1->next << endl;

    // head pointed to
    Node *head = node1;
    Node *tail = node1;
    display(head);

    // insertAthead(head, 12);
    // display(head);

    // insertAthead(head, 15);
    // display(head);

    // so we learnt how to make a linked list but in this method   the last entered element in inserted to the first position and so on.
    // So Inorder to change this order we got to make tail

    insertAtTail(tail, 12);
    display(head);

    insertAtTail(tail, 15);
    display(head);

    insert(tail, head, 1, 22);
    display(head);

    deletion(tail, head, 4);
    display(head);

    cout << "head is pointing to " << head->data << endl;
    cout << "Tail is pointing to " << tail->data << endl;
    return 0;
}