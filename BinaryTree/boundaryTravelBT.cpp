#include <stack>
#include <vector>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *root)
{
    return root->left == NULL && root->right == NULL;
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}
void addRightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *curr = root->right;
    stack<int> st;
    while (curr)
    {
        if (!isLeaf(curr))
            st.push(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    if (!isLeaf(root))
        ans.push_back(root->data); // root, only if not leaf

    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    return ans;
}
