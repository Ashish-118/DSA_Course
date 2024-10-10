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
void Iterativereverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}


Node *Kreverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *forward = NULL;
    Node *prev = NULL;
    Node *curr = head;
    int count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != NULL)
    {
        head->next = Kreverse(forward, k);
    }
    return prev;
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
    Insert(tail, 3);
    // Insert(tail, 8);
    print(head);

head=Kreverse(head,2);

    print(head);
    return 0;
}