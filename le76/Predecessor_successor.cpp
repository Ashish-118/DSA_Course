void solve(TreeNode *root, int key, int &p, int &s, bool &c)
{
    if (root == NULL)
        return;

    solve(root->left, key, p, s, c);
    if (root->data < key)
        p = root->data;
    else if (c && root->data != key)
    {
        s = root->data;
        c = false;
    }
    solve(root->right, key, p, s, c);
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int predecessor = -1, successor = -1;
    bool c = true;
    solve(root, key, predecessor, successor, c);

    return {predecessor, successor};
}