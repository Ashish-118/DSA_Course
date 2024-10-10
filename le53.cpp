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

void removeDuplicates(Node *&head)
{
    map<int, bool> visited;

    Node *temp = head;
    Node *prev = head;
    while (temp != NULL)
    {
        if (visited[temp->data]==false)
        {
            visited[temp->data] = true;

            prev = temp;
            temp = temp->next;
        }
        else
        {
            Node *toDelete = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete (toDelete);
        }
    }
}
int main()
{
    // hOMEWORK

    Node *node = new Node(10);
    Node *tail = node;
    Node *head = node;
    Insert(tail, -2);
    Insert(tail, 2);
    Insert(tail, 4);
    Insert(tail, 3);
    Insert(tail, 2);
    Insert(tail, 4);

    print(head);
    removeDuplicates(head);
    print(head);


    return 0;
}