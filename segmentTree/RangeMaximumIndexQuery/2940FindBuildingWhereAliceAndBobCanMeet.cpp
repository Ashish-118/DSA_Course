class Solution
{
public:
    vector<int> seg;

    void build(int i, int l, int r, vector<int> &heights)
    {
        if (l == r)
        {
            seg[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;
        build(2 * i + 1, l, mid, heights);
        build(2 * i + 2, mid + 1, r, heights);

        if (heights[seg[2 * i + 1]] > heights[seg[2 * i + 2]])
        {
            seg[i] = seg[2 * i + 1];
        }
        else
        {
            seg[i] = seg[2 * i + 2];
        }
    }

    int RMIQ(int i, int l, int r, int start, int end, vector<int> &heights)
    {
        if (l > end || r < start)
        {
            return -1;
        }
        else if (l >= start && r <= end)
        {
            return seg[i];
        }

        int mid = l + (r - l) / 2;

        int left = RMIQ(2 * i + 1, l, mid, start, end, heights);
        int right = RMIQ(2 * i + 2, mid + 1, r, start, end, heights);

        int minIdx = -1;

        if (left != -1 && right != -1)
        {
            if (heights[left] > heights[right])
            {
                minIdx = left;
            }
            else
            {
                minIdx = right;
            }
        }
        else if (left != -1)
        {
            minIdx = left;
        }
        else
        {
            minIdx = right;
        }

        return minIdx;
    }
    vector<int> leftmostBuildingQueries(vector<int> &heights,
                                        vector<vector<int>> &queries)
    {
        int n = heights.size();
        seg.assign(4 * n, -1);
        build(0, 0, n - 1, heights);
        vector<int> ans;

        for (auto q : queries)
        {
            if (q[0] == q[1])
            {
                ans.push_back(q[0]);
            }
            else
            {
                int maxidx = max(q[0], q[1]);
                int minidx = min(q[0], q[1]);

                if (heights[maxidx] > heights[minidx])
                {
                    ans.push_back(maxidx);
                    continue;
                }

                int lo = maxidx + 1, hi = n - 1;

                int res = -1;

                while (lo <= hi)
                {
                    int mid = lo + (hi - lo) / 2;
                    int idx = RMIQ(0, 0, n - 1, lo, mid, heights);
                    if (heights[idx] > heights[q[0]] &&
                        heights[idx] > heights[q[1]])
                    {
                        res = idx;
                        hi = mid - 1;
                    }
                    else
                    {
                        lo = mid + 1;
                    }
                }

                ans.push_back(res);
            }
        }

        return ans;
    }
};