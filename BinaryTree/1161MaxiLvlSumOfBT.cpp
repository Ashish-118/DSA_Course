/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int lvl = 1;
        queue<TreeNode *> q;
        q.push(root);
        int maxi = INT_MIN;
        int ans = -1;

        while (!q.empty())
        {
            int size = q.size();
            int sum = 0;
            for (int k = 0; k < size; k++)
            {
                auto front = q.front();
                q.pop();
                sum += front->val;
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            if (maxi < sum)
            {
                maxi = sum;
                ans = lvl;
            }
            lvl++;
        }

        return ans;
    }
};