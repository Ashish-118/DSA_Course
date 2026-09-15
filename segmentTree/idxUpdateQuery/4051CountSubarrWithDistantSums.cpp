class Solution
{
public:
    vector<long long> prefix;
    vector<long long> seg;
    vector<long long> rank;

    void addFreq(int i, int l, int r, int idx)
    {
        if (l == r)
        {
            seg[i]++;
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
        {
            addFreq(2 * i + 1, l, mid, idx);
        }
        else
        {
            addFreq(2 * i + 2, mid + 1, r, idx);
        }

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    long long getRange(int i, int l, int r, int s, int e)
    {
        if (r < s || l > e)
        {
            return 0;
        }
        else if (l >= s && r <= e)
        {
            return seg[i];
        }

        int mid = l + (r - l) / 2;

        long long left = getRange(2 * i + 1, l, mid, s, e);
        long long right = getRange(2 * i + 2, mid + 1, r, s, e);

        return left + right;
    }

    long long distantSubarrays(vector<int> &nums, int goal, int k)
    {
        int n = nums.size();

        prefix.assign(n, 0);

        prefix[0] = nums[0];

        set<long long> st;
        st.insert(prefix[0]);

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
            st.insert(prefix[i]);
        }

        for (auto &x : st)
        {
            rank.push_back(x);
        }

        int m = rank.size();

        seg.assign(4 * m, 0);

        long long all = (1LL * n * (n + 1)) / 2;

        long long bad = 0;

        for (int i = 0; i < n; i++)
        {
            long long left = prefix[i] - goal - k;
            long long right = prefix[i] + k - goal;

            if (abs(prefix[i] - goal) < k)
            {
                bad++;
            }

            auto it = lower_bound(rank.begin(), rank.end(), prefix[i]);

            int index = it - rank.begin();

            int l = upper_bound(rank.begin(), rank.end(), left) - rank.begin();
            int r = upper_bound(rank.begin(), rank.end(), right - 1) -
                    rank.begin() - 1;

            int get = getRange(0, 0, m - 1, l, r);
            bad += get;

            addFreq(0, 0, m - 1, index);
        }

        return all - bad;
    }
};