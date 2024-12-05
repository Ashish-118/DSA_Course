#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;

    node(int d)
    {
        data = d;
        prev = NULL;
    }
};

class Stack
{
public:
    node *top;
    node *rear;
    int size;
    Stack(int s)
    {
        top = NULL;
        rear = NULL;
        size = s;
    }

    void push(int d)
    {
        node *newNode = new node(d);
        if (top == NULL)
        {
            top = newNode;
            rear = newNode;
            return;
        }
        else
        {
            newNode->prev = top;
            top = newNode;
        }
    }
    bool isempty()
    {
        return top == NULL ? true : false;
    }
    int pop()
    {
        if (!isempty())
        {
            int popped = top->data;
            node *temp = top;
            top = top->prev;
            temp->prev = NULL;
            delete temp;
            return popped;
        }
        return -1;
    }
};
int main()
{

    Stack s1(5);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.push(56);
    s1.push(9);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    // cout << s1.pop() << endl;
    cout << s1.isempty() << endl;

    return 0;
}