vector<int> getTopView(TreeNode<int> *root)
{
    map<int, int> m;
    vector<int> ans;

    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto front = q.front();
        TreeNode<int> *node = front.first;
        int col = front.second;
        q.pop();

        if (m.count(col) == 0)
        {
            m[col] = node->data;
        }

        if (node->left != NULL)
            q.push({node->left, col - 1});
        if (node->right != NULL)
            q.push({node->right, col + 1});
    }
    for (auto &x : m)
    {
        ans.push_back(x.second);
    }
    return ans;
}
