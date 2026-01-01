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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;

        int lvl = 0;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();

            int check = (lvl % 2 == 0 ? INT_MIN : INT_MAX);
            while (n--)
            {
                auto front = q.front();
                int value = front->val;
                q.pop();

                if (lvl & 1)
                {
                    if (value & 1 || value >= check)
                        return false;
                }
                else
                {
                    if (value % 2 == 0 || check >= value)
                        return false;
                }

                check = value;

                if (front->left != nullptr)
                {
                    q.push(front->left);
                }
                if (front->right != nullptr)
                {
                    q.push(front->right);
                }
            }

            lvl++;
        }

        return true;
    }
};