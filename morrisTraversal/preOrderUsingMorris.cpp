#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node *&root)
{
    if (root == NULL)
    {
        cout << "enter the value of the root node: ";
        int cinVal;
        cin >> cinVal;
        root = new Node(cinVal);
    }
    cout << "Enter the left node of " << root->data << ": ";
    int leftVal;
    cin >> leftVal;
    if (leftVal != -1)
    {
        root->left = new Node(leftVal);
        insert(root->left);
    }

    cout << "Enter the right node of " << root->data << ": ";
    int rightVal;
    cin >> rightVal;
    if (rightVal != -1)
    {
        root->right = new Node(rightVal);
        insert(root->right);
    }
}

void print(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

void preorderWithMorrisTraversel(Node *root)
{
    Node *current = root;

    auto predecessor = [&](Node *node)
    {
        Node *temp = node->left;
        while (temp->right != NULL && temp->right != node)
        {
            temp = temp->right;
        }
        return temp;
    };

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            Node *pred = predecessor(current);

            if (pred->right == NULL)
            {
                cout << current->data << " ";
                pred->right = current;
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    insert(root);
    print(root);
    cout << endl;
    cout << "here we are doing preorder traversal using morris traversal concept" << endl;
    preorderWithMorrisTraversel(root);
    cout << endl;

    return 0;
}