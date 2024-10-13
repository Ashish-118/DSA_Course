#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *createBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
        root->left = createBST(root->left, data);
    else
        root->right = createBST(root->right, data);

    return root;
}

void takeInput(Node *&root)
{

    int d;
    cin >> d;
    while (d != -1)
    {
        root = createBST(root, d);

        cin >> d;
    }
}
void levelOrderTraversals(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{

    Node *root = NULL;

    takeInput(root);
    // cout << root->data << endl;
    levelOrderTraversals(root);
    return 0;
}