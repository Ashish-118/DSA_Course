#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree()
{
    cout << "Enter the data (-1 for no node): " << endl;
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    Node *root = new Node(d);

    cout << "Enter the data for inserting in the left of " << d << endl;
    root->left = buildTree();

    cout << "Enter the data for inserting in the right of " << d << endl;
    root->right = buildTree();

    return root;
}

pair<bool, int> sum_tree(Node *root)
{

    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true,0);
        return p;
    }
    if (root != NULL && root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = sum_tree(root->left);
    pair<bool, int> right = sum_tree(root->right);
    bool op1 = left.first;
    bool op2 = right.first;
    bool diff = (left.second + right.second) == root->data;

    pair<bool, int> ans;
    ans.second = left.second + right.second + root->data;
    if (op1 && op2 && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree();
    pair<bool, int> result = sum_tree(root);
    cout << (result.first ? "Yes, it is a Sum tree" : "NO it's not") << endl;
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
