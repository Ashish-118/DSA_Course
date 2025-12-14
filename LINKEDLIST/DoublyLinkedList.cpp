#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            this->prev = NULL;
        }

        cout << "Destructor has been called " << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(Node *&head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void insertAtHead(Node *&tail, Node *&head, int element)
{

    if (head == NULL)
    {
        Node *temp = new Node(element);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *newNode = new Node(element);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int element)
{
    if (tail == NULL)
    {
        Node *temp = new Node(element);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *newNode = new Node(element);

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insert(Node *&tail, Node *&head, int element, int pos)
{
    Node *newNode = new Node(element);
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;

        // or
        // insertAtHead(head,element);
        // return;
    }
    else
    {
        Node *prev = head;
        Node *curr = head;

        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (prev->next == NULL)
        {
            prev->next = newNode;
            newNode->prev = prev;
            tail = newNode;
        }
        else
        {
            prev->next = newNode;
            curr->prev = newNode;
            newNode->next = curr;
            newNode->prev = prev;
        }
    }
}

void Deletion(Node *&tail, Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // Node *node1 = new Node(10);
    // Node *head = node1;
    // Node *tail = node1;

    ///    when we  no initiation point   or   empty list
    Node *head = NULL;
    Node *tail = NULL;
    // print(head);

    // cout << "The length of the Doubly Linked List is " << getlength(head) << endl;

    //  to the insert element at the head
    insertAtHead(tail, head, 5);
    insertAtHead(tail, head, 7);
    // print(head);

    // cout << "Head is pointing to " << head->data << endl;

    // to insert the element to the tail

    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 8);
    // print(head);

    insert(tail, head, 44, 1);
    insert(tail, head, 89, 6);
    print(head);

    Deletion(tail,head, 6);
    print(head);
    cout << "Head is pointing to " << head->data << endl;
    cout << "Tail is pointing to " << tail->data << endl;
    return 0;
}