struct TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;

    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(TrieNode *root, int num)
{
    TrieNode *traverse = root;

    for (int i = 31; i >= 0; i--)
    {
        int ithBit = (num >> i) & 1;

        if (ithBit)
        {
            if (traverse->right == NULL)
            {
                traverse->right = new TrieNode();
                traverse = traverse->right;
            }
            else
            {
                traverse = traverse->right;
            }
        }
        else
        {
            if (traverse->left == NULL)
            {
                traverse->left = new TrieNode();
                traverse = traverse->left;
            }
            else
            {
                traverse = traverse->left;
            }
        }
    }
}

int findMaxXor(TrieNode *root, int val)
{
    TrieNode *traverse = root;
    int maxXor = 0;

    for (int i = 31; i >= 0; i--)
    {
        int ithBit = (val >> i) & 1;

        if (ithBit == 0)
        {
            if (traverse->right != NULL)
            {
                traverse = traverse->right;
                maxXor += pow(2, i);
            }
            else
            {
                traverse = traverse->left;
            }
        }
        else
        {
            if (traverse->left != NULL)
            {
                traverse = traverse->left;
                maxXor += pow(2, i);
            }
            else
            {
                traverse = traverse->right;
            }
        }
    }

    return maxXor;
}

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        sort(nums.begin(), nums.end());

        TrieNode *root = new TrieNode();
        int i = 0;
        for (auto &q : queries)
        {
            q.push_back(i++);
        }

        int n = queries.size();
        vector<int> ans(n);

        auto cmp = [](vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        };
        sort(begin(queries), end(queries), cmp);

        int x = 0;
        for (auto &q : queries)
        {
            while (x < nums.size() && nums[x] <= q[1])
            {
                insert(root, nums[x]);
                x++;
            }
            if (x == 0)
            {
                ans[q[2]] = -1;
            }
            else
            {
                ans[q[2]] = findMaxXor(root, q[0]);
            }
        }
        return ans;
    }
};
