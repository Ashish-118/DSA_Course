/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *newRoot;
    vector<int> arr;
    TreeNode *solve(int s, int e)
    {
        if (s > e)
            return nullptr;
        int mid = s + (e - s) / 2;
        TreeNode *root = new TreeNode(arr[mid]);

        root->left = solve(s, mid - 1);
        root->right = solve(mid + 1, e);

        return root;
    }
    void inorder(TreeNode *root)
    {

        if (root == nullptr)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        inorder(root);
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
        return solve(0, arr.size() - 1);
    }
};