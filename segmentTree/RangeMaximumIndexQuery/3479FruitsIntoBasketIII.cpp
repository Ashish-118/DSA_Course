class Solution
{
public:
    vector<int> seg;

    void build(int i, int l, int r, vector<int> &baskets)
    {
        if (l == r)
        {
            seg[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, baskets);
        build(2 * i + 2, mid + 1, r, baskets);

        int leftIdx = seg[2 * i + 1];
        int rightIdx = seg[2 * i + 2];

        if (baskets[leftIdx] > baskets[rightIdx])
        {
            seg[i] = leftIdx;
        }
        else
        {
            seg[i] = rightIdx;
        }
    }

    void updateSeg(int i, int l, int r, vector<int> &baskets, int idx)
    {
        if (l == r)
        {
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
        {
            updateSeg(2 * i + 1, l, mid, baskets, idx);
        }
        else
        {
            updateSeg(2 * i + 2, mid + 1, r, baskets, idx);
        }

        int leftIdx = seg[2 * i + 1];
        int rightIdx = seg[2 * i + 2];

        if (baskets[leftIdx] > baskets[rightIdx])
        {
            seg[i] = leftIdx;
        }
        else
        {
            seg[i] = rightIdx;
        }
    }

    int RMIQ(int i, int l, int r, int start, int end, vector<int> &baskets)
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

        int leftIdx = RMIQ(2 * i + 1, l, mid, start, end, baskets);
        int rightIdx = RMIQ(2 * i + 2, mid + 1, r, start, end, baskets);

        if (leftIdx == -1)
        {
            return rightIdx;
        }
        else if (rightIdx == -1)
        {
            return leftIdx;
        }

        int ret = -1;

        if (baskets[leftIdx] > baskets[rightIdx])
        {
            ret = leftIdx;
        }
        else
        {
            ret = rightIdx;
        }

        return ret;
    }

    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();
        seg.assign(4 * n, 0);
        build(0, 0, n - 1, baskets);

        int fruits_cannot_be_allocated = 0;

        for (auto x : fruits)
        {
            int lo = 0, hi = n - 1;
            int ans = -1;

            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                int idx = RMIQ(0, 0, n - 1, lo, mid, baskets);
                if (baskets[idx] >= x)
                {
                    ans = idx;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }

            if (ans == -1)
            {
                fruits_cannot_be_allocated++;
                continue;
            }

            baskets[ans] = 0;

            updateSeg(0, 0, n - 1, baskets, ans);
        }

        return fruits_cannot_be_allocated;
    }
};