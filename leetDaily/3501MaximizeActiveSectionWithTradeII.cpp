using namespace std;

class Solution
{
public:
    vector<int> seg;
    vector<int> blockStart, blockEnd, blockSize;
    vector<int> pairSum;

    void buildSeg(int i, int l, int r)
    {
        if (l == r)
        {
            seg[i] = pairSum[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSeg(2 * i + 1, l, mid);
        buildSeg(2 * i + 2, mid + 1, r);

        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }

    int RMQ(int i, int l, int r, int start, int end)
    {
        if (l > end || r < start)
            return 0;

        if (l >= start && r <= end)
            return seg[i];

        int mid = l + (r - l) / 2;

        return max(
            RMQ(2 * i + 1, l, mid, start, end),
            RMQ(2 * i + 2, mid + 1, r, start, end));
    }

    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>> &queries)
    {

        int n = s.length();

        int startIdx = -1, endIdx = -1, size = 0;

        for (int i = 0; i < n; i++)
        {

            if (size == 0 && s[i] == '0')
            {
                startIdx = endIdx = i;
                size = 1;
            }
            else if (s[i] == '0')
            {
                endIdx = i;
                size++;
            }
            else
            {

                if (startIdx != -1)
                {
                    blockStart.push_back(startIdx);
                    blockEnd.push_back(endIdx);
                    blockSize.push_back(size);
                }

                startIdx = endIdx = -1;
                size = 0;
            }
        }

        if (startIdx != -1)
        {
            blockStart.push_back(startIdx);
            blockEnd.push_back(endIdx);
            blockSize.push_back(size);
        }

        int noOfBlocks = blockSize.size();

        int activeCount = std::count(s.begin(), s.end(), '1');

        if (noOfBlocks < 2)
        {
            return vector<int>(queries.size(), activeCount);
        }

        seg.assign(4 * noOfBlocks, 0);

        for (int i = 0; i < noOfBlocks - 1; i++)
        {
            pairSum.push_back(blockSize[i] + blockSize[i + 1]);
        }

        pairSum.push_back(0);

        buildSeg(0, 0, noOfBlocks - 1);

        vector<int> ans;

        for (auto &q : queries)
        {

            int start = q[0];
            int end = q[1];

            int low =
                lower_bound(blockEnd.begin(), blockEnd.end(), start) -
                blockEnd.begin();

            int high =
                upper_bound(blockStart.begin(), blockStart.end(), end) -
                blockStart.begin() - 1;

            if (low >= high)
            {
                ans.push_back(activeCount);
                continue;
            }

            int firstLen =
                blockEnd[low] - max(blockStart[low], start) + 1;

            int lastLen =
                min(blockEnd[high], end) - blockStart[high] + 1;

            if (high - low == 1)
            {
                ans.push_back(activeCount + firstLen + lastLen);
                continue;
            }

            int frontPairSum = firstLen + blockSize[low + 1];

            int lastPairSum = blockSize[high - 1] + lastLen;

            int rmq = RMQ(0, 0, noOfBlocks - 1,
                          low + 1,
                          high - 2);

            ans.push_back(activeCount +
                          max({frontPairSum,
                               lastPairSum,
                               rmq}));
        }

        return ans;
    }
};