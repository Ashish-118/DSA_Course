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

Node *reverse(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (cur != NULL)
    {

        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node *GetMiddlen(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
bool Palindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *mid = GetMiddlen(head);
    mid->next = reverse(mid->next);

    Node *head1 = head;
    Node *head2 = mid->next;

    while (head2 != NULL)
    {

        if (head1->data != head2->data)
        {
            return false;
        }
        head2 = head2->next;
        head1 = head1->next;
    }

    // this is an optional for  removing our edit in the given linked list
    mid->next = reverse(mid->next);
    return true;
}
int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    Insert(tail, 1);
    Insert(tail, 2);
    Insert(tail, 2);
    Insert(tail, 1);
    Insert(tail, 1);
    print(head);

    cout << "\n " << Palindrome(head) << " \n"
         << endl;
    return 0;
}