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

void reverse(Node *&head, Node *curr, Node *prev)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
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
    print(head);
    // Iterativereverse(head);
    // print(head);
 
    Node *prev=NULL;
    Node *curr=head;
    reverse(head,curr,prev);
    print(head);
    return 0;
}