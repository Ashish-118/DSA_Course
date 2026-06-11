class segmentTree
{
public:
    pair<int, int> *seg;
    segmentTree(int n) { seg = new pair<int, int>[4 * n]; }

    void buildTree(vector<int> &nums, int i, int l, int r)
    {
        if (l == r)
        {
            seg[i] = {nums[l], nums[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        buildTree(nums, 2 * i + 1, l, mid);
        buildTree(nums, 2 * i + 2, mid + 1, r);

        seg[i] = {min(seg[2 * i + 1].first, seg[2 * i + 2].first),
                  max(seg[2 * i + 1].second, seg[2 * i + 2].second)};
    }

    pair<int, int> GetRangeMinMaxQuery(int i, int l, int r, int start,
                                       int end)
    {
        if (l > end || r < start)
        {
            return {-1, -1};
        }
        else if (start <= l && r <= end)
        {
            return seg[i];
        }
        int mid = l + (r - l) / 2;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        auto a1 = GetRangeMinMaxQuery(2 * i + 1, l, mid, start, end);
        auto a2 = GetRangeMinMaxQuery(2 * i + 2, mid + 1, r, start, end);

        if (a1 != make_pair(-1, -1))
        {
            mini = min(mini, a1.first);
            maxi = max(maxi, a1.second);
        }

        if (a2 != make_pair(-1, -1))
        {
            mini = min(mini, a2.first);
            maxi = max(maxi, a2.second);
        }

        return {mini, maxi};
    }
};
class Solution
{
public:
    using pp = pair<int, pair<int, int>>;

    long long maxTotalValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        segmentTree s(n);
        s.buildTree(nums, 0, 0, n - 1);

        priority_queue<pp, vector<pp>> pq;

        for (int l = 0; l < n; l++)
        {
            auto v = s.GetRangeMinMaxQuery(0, 0, n - 1, l, n - 1);
            int val = abs(v.first - v.second);
            pq.push({val, {l, n - 1}});
        }

        long long result = 0;

        while (k--)
        {
            auto top = pq.top();
            pq.pop();
            auto sub = top.second;
            result += top.first;

            if (sub.first < sub.second)
            {
                auto v = s.GetRangeMinMaxQuery(0, 0, n - 1, sub.first,
                                               sub.second - 1);
                int val = abs(v.first - v.second);
                pq.push({val, {sub.first, sub.second - 1}});
            }
        }

        return result;
    }
};