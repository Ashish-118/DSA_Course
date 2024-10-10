#include <iostream>
using namespace std;

class stack
{
public:
    int top;
    int size;
    int *arr;

    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
       
        top--;
    }

    void Push(int x)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    bool isEmpty(){
        if (top==-1)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
    int peek(){
        if (top>=0)
        {
           return arr[top];
        }
        else{
            return -1;
        }
        
    }
};
int main()
{
    stack s(5);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50); // Stack Overflow
    cout << "Top element is: " << s.peek() << endl;

    s.Pop();

    cout << "Top element is: " << s.peek() << endl;
    s.Pop();
    s.Pop();
    s.Pop();

    // s.Pop();
    cout<<"is the array is empty! "<<s.isEmpty()<<endl;
    cout << "Top element is: " << s.peek() << endl;

    return 0;
}