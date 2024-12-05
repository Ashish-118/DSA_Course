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

int balanced(Node *root, bool &check)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = balanced(root->left, check);
    int right = balanced(root->right, check);
    int diff = abs(left - right);

    if (check)
    {
        check = (diff <= 1) && check ? true : false;
    }

    return max(left, right) + 1;
}

pair<bool, int> balanced_unbalanced(Node *root)
{

    if (root == NULL)
    {
        pair<int, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = balanced_unbalanced(root->left);
    pair<bool, int> right = balanced_unbalanced(root->right);
    bool op1 = left.first;
    bool op2 = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
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
    bool check = true;
    balanced(root, check);
    cout << (check ? "balanced" : "unbalanced") << endl;
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
