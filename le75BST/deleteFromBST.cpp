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

Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// maxval

Node *maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
    {
        root->left = deleteFromBST(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteFromBST(root->right, val);
    }
    else
    { // Found the node to delete
        // Case 1: Node with no children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: Node with only one child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        if (root->left != NULL && root->right != NULL)
        {
            Node *successor = minVal(root->right);
            root->data = successor->data;
            root->right = deleteFromBST(root->right, successor->data);
        }
    }
    return root;
}
int main()
{

    Node *root = NULL;

    takeInput(root);
    // cout << root->data << endl;
    levelOrderTraversals(root);
    return 0;
}