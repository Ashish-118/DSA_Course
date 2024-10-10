#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Node
{
public:
    string task;
    Node *next;

    Node(string task)
    {
        this->task = task;
        this->next = nullptr;
    }
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = nullptr;
    }

    void push(string task)
    {
        Node *newNode = new Node(task);
        newNode->next = top;
        top = newNode;
    }

    string pop()
    {
        if (isEmpty())
        {
            return "";
        }
      string task = top->task;
        Node *temp = top;
        top = top->next;
        delete temp;
        return task;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

class RobotTaskManager
{
private:
    Stack regularStack;
    Stack highPriorityStack;

public:
    void addTask(string task)
    {
        if (rand() % 100 < 40)
        {
            cout << "Adding high-priority task: " << task << endl;
            highPriorityStack.push(task);
        }
        else
        {
            cout << "Adding regular task: " << task << endl;
            regularStack.push(task);
        }
    }

    void processTasks()
    {
        cout << "\nProcessing tasks...\n"
                  << endl;
        while (!highPriorityStack.isEmpty() || !regularStack.isEmpty())
        {
            if (!highPriorityStack.isEmpty())
            {
                string task = highPriorityStack.pop();
                cout << "Processing high-priority task: " << task << endl;
            }
            else if (!regularStack.isEmpty())
            {
                string task = regularStack.pop();
                cout << "Processing regular task: " << task << endl;
            }
        }
    }
};

// Main function
int main()
{
    srand(time(0));

    RobotTaskManager robot;
    int numTasks;

    cout << "Enter the total number of tasks: ";
    cin >> numTasks;

    for (int i = 1; i <= numTasks; i++)
    {
        string taskName = "Task_" + to_string(i);
        robot.addTask(taskName);
    }

    robot.processTasks();

    return 0;
}
