class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> q;
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<TreeNode *, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode *frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto &p : nodes)
        {
            vector<int> vertical;
            for (auto &q : p.second)
            {
                sort(q.second.begin(), q.second.end());
                vertical.insert(vertical.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};