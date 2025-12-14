#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp->next != tail);
    cout << endl;
}

void insertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
bool CycleDetection(Node *head)
{
    map<Node *, bool> visited;

    Node *temp = head;
    while (temp != NULL)
    {
        if (~visited[temp])
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
int main()
{

    Node *tail = NULL;

    insertNode(tail, 5, 8); // EMPTY CASE
    insertNode(tail, 8, 4);
    insertNode(tail, 4, 1);
    insertNode(tail, 4, 9);
    print(tail);
    cout<<CycleDetection(tail)<<endl;
    return 0;
}