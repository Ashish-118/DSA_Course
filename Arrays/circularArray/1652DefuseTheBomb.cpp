class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            if (k > 0)
            {
                for (int j = 1; j <= k; j++)
                {
                    int x = (i + j) % n;
                    sum += code[x];
                }
            }
            else
            {
                for (int j = -1; j >= k; j--)
                {
                    int x = (((i + j) % n) + n) % n;
                    sum += code[x];
                }
            }

            ans[i] = sum;
        }

        return ans;
    }
};
// Time Complexity: O(n^2)

// optimal approach using prefix sum

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();

        vector<int> ans(n, 0);
        vector<int> prefix(n, 0);
        prefix[0] = code[0];

        for (int i = 1; i < n; i++)
            prefix[i] = code[i] + prefix[i - 1];

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            if (k == 0)
                continue;
            else if (k > 0)
            {
                int x = (i + k) % n;
                if (x > i)
                {
                    sum += (prefix[x] - prefix[i]);
                }
                else
                { // circular to the right
                    sum += (prefix[x] + prefix[n - 1] - prefix[i]);
                }
            }
            else
            {
                int x = (((i + k) % n) + n) % n;

                if (x < i)
                {
                    sum += (prefix[i - 1] - (x > 0 ? prefix[x - 1] : 0));
                }
                else
                {
                    sum += ((i > 0 ? prefix[i - 1] : 0) +
                            (prefix[n - 1] - prefix[x - 1]));
                }
            }

            ans[i] = sum;
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)