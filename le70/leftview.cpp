// vector<int> printLeftView(BinaryTreeNode<int>* root) {
//           map<int, pair<int, int>> m;
//     queue<pair<BinaryTreeNode<int> *, int>> q;
//     vector<int> ans;
//     if (root == NULL)
//         return ans;
//     q.push(make_pair(root, 0));

//     while (!q.empty())
//     {
//         pair<BinaryTreeNode<int> *, int> temp = q.front();
//         q.pop();

//         int lvl = temp.second;
//         if (m[lvl].first != 1)
//         {
//             m[lvl].first = 1;
//             m[lvl].second = temp.first->data;
//         }

//         if (temp.first->left)
//             q.push(make_pair(temp.first->left, lvl + 1));
//         if (temp.first->right)
//             q.push(make_pair(temp.first->right, lvl + 1));
//     }
//     for (auto i : m)
//     {
//         ans.push_back(i.second.second);
//     }
//     return ans;
// }




// Method 2
void solve(Node *root, vector < int &ans, int level)
{
    // /base case
    if (root = NULL)
        return;
    // /we entered into a new level
    if (level = ans.size())
        ans.push_back(root->data);
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}