vector<int> getTopView(TreeNode<int> *root)
{
    map<int, pair<int, int>> m;
    queue<pair<TreeNode<int> *, int>> q;
    vector<int> ans;
    if (root == NULL)
        return ans;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<TreeNode<int> *, int> temp = q.front();
        q.pop();

        int Horizontal_dist = temp.second;
        if (m[Horizontal_dist].first != 1)
        {
            m[Horizontal_dist].first = 1;
            m[Horizontal_dist].second = temp.first->data;
        }

        if (temp.first->left)
            q.push(make_pair(temp.first->left, Horizontal_dist - 1));
        if (temp.first->right)
            q.push(make_pair(temp.first->right, Horizontal_dist + 1));
    }
    for (auto i : m)
    {
        ans.push_back(i.second.second);
    }
    return ans;
}