#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int data;
    Stack *next;
    Stack *head;
    Stack()
    {
        head = NULL;
    }
    Stack(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void push(int element)
    {
        if (head == NULL)
        {
            head = new Stack(element);
            return;
        }
        Stack *newStack = new Stack(element);
        newStack->next = head;
        head = newStack;
    }

    int peek()
    {
        return (head != NULL) ? head->data : -1;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty\n";
            return;
        }
        Stack *temp = head;
        head = head->next;
        delete temp;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    Stack s; 
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50); // Stack Overflow
    // cout << "Top element is: " << s.peek() << endl;

    // s.pop();

    // cout << "Top element is: " << s.peek() << endl;
    // s.pop();
    // s.pop();
    // s.pop();

    // // s.pop();
    // cout << "is the array is empty! " << s.isEmpty() << endl;
    // cout << "Top element is: " << s.peek() << endl;
    return 0;
}