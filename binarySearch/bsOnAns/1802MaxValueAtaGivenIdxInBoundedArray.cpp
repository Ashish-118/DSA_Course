class Solution
{
public:
    int poss(int mid, int n, int index, int maxSum)
    {
        long long sum = mid;
        int Prefixlen1 =
            min(mid - 1, index); // index tells no of element before index

        int PrefixOnes = index - Prefixlen1;
        sum += (1LL * Prefixlen1 * mid -
                ((1LL * Prefixlen1 * (Prefixlen1 + 1)) / 2) + PrefixOnes);

        int rightLen = n - (index + 1);
        int suffixLen1 = min(mid - 1, rightLen);
        int suffixOnes = rightLen - suffixLen1;

        sum += (1LL * suffixLen1 * mid -
                ((1LL * suffixLen1 * (suffixLen1 + 1)) / 2) + suffixOnes);

        return sum <= maxSum;
    }

    int maxValue(int n, int index, int maxSum)
    {
        long long l = 1, r = maxSum;
        int ans = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (poss(mid, n, index, maxSum))
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};