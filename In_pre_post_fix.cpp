#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    char data;
    Stack *next;

    Stack *head = NULL;

    Stack(char data)
    {
        this->data = data;
        this->next = NULL;
    }
    void push(char element)
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

    char peek()
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

int priority(char oper)
{

    if (oper == '+' || oper == '-')
        return 1;
    else if (oper == '*' || oper == '/')
        return 2;
    else if (oper == '^')
        return 3;

    return 0;
}
string inf_to_post(string s, Stack st)
{

    string to_insert = "({[-+*/%";
    string operators = "+-*/^";
    string user = " ";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            while (true)
            {
                char x = st.peek();
                if (x == '(' || x == '{' || x == '[')
                {
                    st.pop();
                    break;
                }
                else
                {
                    user += st.peek();
                    st.pop();
                }
            }
        }
        else if (operators.find(s[i]) != string::npos)
        {
            while (true)
            {
                if (priority(s[i]) > priority(st.peek()))
                    break;
                else
                    st.pop();
            }
            st.push(s[i]);
        }
        else
        {
            if (to_insert.find(s[i]) != string::npos)
                st.push(s[i]);

            else
                user += s[i];
        }
    }

    while (true)
    {
        if (st.isEmpty())
        {
            break;
        }
        else
        {
            user += st.peek();
            st.pop();
        }
    }
    return user;
}

string rev(string s)
{
    string r_s = " ";
    string y = "({[]})";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int f=y.find(s[i]);
        if (f!=string::npos)
        {
            s[i] = y[5 - f];
        }

        r_s += s[i];
    }


    return r_s;

    
}


string inf_to_prefix(string s,Stack st){

string n=rev(s);
string p=inf_to_post(n,st);

return rev(p);
}

int main()
{

    string s;
    // string user = " ";
    cin >> s;
    Stack st(s[0]);

    cout << inf_to_post(s, st) << endl;
    cout<<inf_to_prefix(s,st)<<endl;

    return 0;
}