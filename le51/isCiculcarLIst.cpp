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

bool isCircularList(Node *&head)
{
    if (head == NULL)
    {
        return true;
    }

    else
    {
        Node *temp = head->next;
        while (temp != head && temp != NULL)
        {
           temp=temp->next;
        }

        if (temp==NULL)
        {
          return false;
        }
        else{
            return true;
        }
        
    }
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


cout<<"Is this the formed list is circular "<<isCircularList(head)<<endl;

    return 0;
}