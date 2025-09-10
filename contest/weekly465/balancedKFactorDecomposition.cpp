class Solution
{
public:
    vector<int> curr;
    vector<int> res;
    int diff = INT_MAX;

    void solve(int n, int k)
    {
        if (k == 1)
        {
            curr.push_back(n);
            int maxx = *max_element(curr.begin(), curr.end());
            int minx = *min_element(curr.begin(), curr.end());
            int d = maxx - minx;
            if (d < diff)
            {
                diff = d;
                res = curr;
            }
            curr.pop_back();
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                curr.push_back(i);
                solve(n / i, k - 1);
                curr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k)
    {
        solve(n, k);
        return res;
    }
}; // t.c O(n^(k-1)) s.c O(k)