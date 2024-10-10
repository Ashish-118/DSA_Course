
class Solution
{
    void solve(Node *root, vector<int> &path, int &count, int target)
    {
        if (root == NULL)
        {
            return;
        }

        path.push_back(root->data);
        solve(root->left, path, count, target);
        solve(root->right, path, count, target);

        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == target)
            {
                count++;
            }
        }

        path.pop_back();
    }

public:
    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, path, count, k);
        return count;
    }
};

//{ Driver Code Starts.
