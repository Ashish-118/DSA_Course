class Solution
{
public:
    void solve(Node *root, vector<int> &subAns, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL & root->right == NULL)
        {
            subAns.push_back(root->data);
            ans.push_back(subAns);
            subAns.pop_back();
            return;
        }

        subAns.push_back(root->data);

        solve(root->left, subAns, ans);
        solve(root->right, subAns, ans);
        subAns.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> subAns;
        solve(root, subAns, ans);

        return ans;
    }
};