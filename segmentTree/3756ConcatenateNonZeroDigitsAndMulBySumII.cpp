// #define mod 1000000007

// class Solution {
// public:
//     struct Node {
//         int num;
//         int len;
//         int sum;
//     };

//     vector<int> segLen, segNum, segDigitSum;
//     vector<int> pow10;

//     void buildSeg(int i, int l, int r, const string& s) {
//         if (l == r) {
//             if (s[l] != '0') {
//                 int digit = s[l] - '0';
//                 segLen[i] = 1;
//                 segNum[i] = digit;
//                 segDigitSum[i] = digit;
//             }
//             return;
//         }

//         int mid = l + (r - l) / 2;

//         buildSeg(2 * i + 1, l, mid, s);
//         buildSeg(2 * i + 2, mid + 1, r, s);

//         segLen[i] = segLen[2 * i + 1] + segLen[2 * i + 2];
//         segDigitSum[i] = segDigitSum[2 * i + 1] + segDigitSum[2 * i + 2];

//         if (segLen[2 * i + 1] && segLen[2 * i + 2]) {
//             segNum[i] =
//                 ((1LL * segNum[2 * i + 1] * pow10[segLen[2 * i + 2]]) % mod +
//                  segNum[2 * i + 2]) %
//                 mod;
//         } else if (segLen[2 * i + 1]) {
//             segNum[i] = segNum[2 * i + 1];
//         } else {
//             segNum[i] = segNum[2 * i + 2];
//         }
//     }

//     Node getAns(int i, int l, int r, int start, int end) {
//         if (l > end || r < start)
//             return {-1, -1, -1};

//         if (l >= start && r <= end)
//             return {segNum[i], segLen[i], segDigitSum[i]};

//         int mid = l + (r - l) / 2;

//         Node left = getAns(2 * i + 1, l, mid, start, end);
//         Node right = getAns(2 * i + 2, mid + 1, r, start, end);

//         if (left.len == -1)
//             return right;

//         if (right.len == -1)
//             return left;

//         Node res;

//         res.len = left.len + right.len;
//         res.sum = left.sum + right.sum;
//         res.num = ((1LL * left.num * pow10[right.len]) % mod + right.num) % mod;

//         return res;
//     }

//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//         int n = s.size();

//         segLen.assign(4 * n, 0);
//         segNum.assign(4 * n, 0);
//         segDigitSum.assign(4 * n, 0);

//         pow10.assign(n + 1, 1);
//         for (int i = 1; i <= n; i++) {
//             pow10[i] = (1LL * pow10[i - 1] * 10) % mod;
//         }

//         buildSeg(0, 0, n - 1, s);

//         vector<int> ans;
//         ans.reserve(queries.size());

//         for (const auto& q : queries) {
//             Node cur = getAns(0, 0, n - 1, q[0], q[1]);
//             ans.push_back((1LL * cur.num * cur.sum) % mod);
//         }

//         return ans;
//     }
// };

// Approach2 (Pre Storing all relevant Data and using them)
// T.C : O(n+q), n = s.length() and q = total queries
// S.C : O(n)
class Solution
{
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        int n = s.length();

        vector<int> nonZeroCount(n, 0); // non-zero digits count in s[0..i]
        vector<ll> numberUpTo(n, 0);    // number formed from non-zero digits in s[0..i]
        vector<ll> digitSumUpTo(n, 0);  // digit sum of s[0..i]
        vector<ll> pow10(n + 1, 0);     // 10^i

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        numberUpTo[0] = s[0] - '0';
        digitSumUpTo[0] = s[0] - '0';

        for (int i = 1; i < n; i++)
        {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
        }

        for (int i = 1; i < n; i++)
        {
            int digit = s[i] - '0';
            if (digit != 0)
                numberUpTo[i] = (numberUpTo[i - 1] * 10 + digit) % MOD;
            else
                numberUpTo[i] = numberUpTo[i - 1];
        }

        for (int i = 1; i < n; i++)
        {
            digitSumUpTo[i] = digitSumUpTo[i - 1] + (s[i] - '0');
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            ll numBefore = (l == 0) ? 0 : numberUpTo[l - 1];

            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if (subStrLen == 0)
            {
                result[i] = 0;
                continue;
            }

            ll x = (numberUpTo[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % MOD);
        }

        return result;
    }
};