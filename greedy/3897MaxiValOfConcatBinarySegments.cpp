class Solution
{
public:
    int mod = 1000000007;

    int Binarypower(int a, int b)
    {
        long long ans = 1;

        while (b != 0)
        {
            if (b & 1)
            {
                ans = (ans * a) % mod;
            }

            a = (1LL * a * a) % mod;
            b >>= 1;
        }

        return ans;
    }

    int maxValue(vector<int> &nums1, vector<int> &nums0)
    {
        vector<pair<int, int>> v;

        int n = nums1.size();
        int countMSB_setBit = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums0[i] == 0) // when a particular segment has no 0s, then all the 1's in that segment will be used to form the MSB of the binary number formed by concatenating all the segments, so we can directly add the count of 1's in that segment to countMSB_setBit
            {
                countMSB_setBit += nums1[i];
            }
            else
            {
                v.push_back({nums1[i], nums0[i]});
            }
        }

        auto cmp = [&](auto p1, auto p2)
        {
            if (p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        };

        sort(begin(v), end(v), cmp);

        int idx = 0;
        long long ans = 0;

        for (int i = v.size() - 1; i >= 0; i--)
        {
            idx += v[i].second;

            int v1 = Binarypower(2, idx);
            int v2 = (Binarypower(2, v[i].first) - 1 + mod) % mod;

            int v3 = (1LL * v1 * v2) % mod;

            ans = (ans + v3) % mod;

            idx += v[i].first;
        }

        int v1 = Binarypower(2, idx);
        int v2 = (Binarypower(2, countMSB_setBit) - 1 + mod) % mod;

        int v3 = (1LL * v1 * v2) % mod;

        ans = (ans + v3) % mod;

        return ans;
    }
};