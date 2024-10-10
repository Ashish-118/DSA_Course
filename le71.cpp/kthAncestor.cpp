void solve(Node *root, int k, int node, int &c, bool &flag, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (node == root->data)
    {
        flag = false;
        c = 1;
        return;
    }

    solve(root->left, k, node, c, flag, ans);
    if (flag)
        solve(root->right, k, node, c, flag, ans);

    if (c != 0)
    {
        if (c == k)
            ans = root->data;
        c++;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    int check = 0;
    bool flag = true;
    int ans = -1;
    solve(root, k, node, check, flag, ans);
    return ans;
}
