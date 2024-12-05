#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Destructor is called and deleted the element" << endl;
    }
};

void insert(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {

        head = new node(d);
        tail = head;
        return;
    }
    tail->next = new node(d);
    tail = tail->next;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int val, node *&head)
{
    node *temp = head;

    node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            break;
        }
        prev = temp;

        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Node not found" << endl;
    }
    else if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {

        prev->next = temp->next;
    }
    temp->next = NULL;
    delete temp;
}
int main()
{

    node *head = NULL;
    node *tail = NULL;

    insert(head, tail, 10);

    insert(head, tail, 20);

    insert(head, tail, 30);
    print(head);
    deleteNode(20, head);
    print(head);
    return 0;
}