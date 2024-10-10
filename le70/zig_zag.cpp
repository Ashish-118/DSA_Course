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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool leftToright = true;
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *element = q.front();
                q.pop();
                int index = (leftToright ? i : size - i - 1);
                ans[index] = element->val;
                if (element->left)
                    q.push(element->left);
                if (element->right)
                    q.push(element->right);
            }
            result.push_back(ans);
            leftToright = !leftToright;
        }
        return result;
    }
};