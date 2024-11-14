/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void solve(TreeNode<int> *root, vector<TreeNode<int> *> &v)
{
    if (root == NULL)
        return;

    solve(root->left, v);
    v.push_back(root);
    solve(root->right, v);
}

void balanceBST(TreeNode<int> *&root, int s, int e, vector<TreeNode<int> *> v)
{
    if (s > e)
    {
        return;
    }

    int mid = (s + e) / 2;
    TreeNode<int> *to_insert = v[mid];

    root = to_insert;
    root->left = NULL;
    root->right = NULL;

    // left
    balanceBST(root->left, s, mid - 1, v);
    // right
    balanceBST(root->right, mid + 1, e, v);
}
TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<TreeNode<int> *> v;
    solve(root, v);
    TreeNode<int> *root1 = NULL;
    int s = 0, e = v.size() - 1;
    balanceBST(root1, s, e, v);
    return root1;
}
