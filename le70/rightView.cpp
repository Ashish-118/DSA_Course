
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//             map<int, int> m;
//     queue<pair<TreeNode *, int>> q;
//     vector<int> ans;
//     if (root == NULL)
//         return ans;
//     q.push(make_pair(root, 0));

//     while (!q.empty())
//     {
//         pair<TreeNode *, int> temp = q.front();
//         q.pop();

//         int lvl = temp.second;

//             m[lvl] = temp.first->val;
        

//         if (temp.first->left)
//             q.push(make_pair(temp.first->left, lvl + 1));
//         if (temp.first->right)
//             q.push(make_pair(temp.first->right, lvl + 1));
//     }
//     for (auto i : m)
//     {
//         ans.push_back(i.second);
//     }
//     return ans;
//     }
// };


// Method 2
void solve(Node *root, vector < int &ans, int level)
{
    // /base case
    if (root = NULL)
        return;
    // /we entered into a new level
    if (level = ans.size())
        ans.push_back(root->data);
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}