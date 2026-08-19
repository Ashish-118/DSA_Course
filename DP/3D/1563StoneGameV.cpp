// this solution passes 128/132 test cases

// class Solution {
// public:
//     vector<int> prefixSum;
//     int t[500][500];
//     int solve(int i, int j) {
//         if (i >= j) {
//             return 0;
//         }

//         // if(t[i][j]!=-1) return t[i][j];

//         int s = i, e = j;
//         int idx = -1;

//         while (s <= e) {
//             int mid = s + (e - s) / 2;

//             int leftSum = prefixSum[mid] - (i > 0 ? prefixSum[i - 1] : 0);
//             int rightSum = prefixSum[j] - prefixSum[mid];

//             if (leftSum <= rightSum) {
//                 idx = mid;
//                 s = mid + 1;
//             } else {
//                 e = mid - 1;
//             }
//         }

//         if (idx != -1) {
//             int leftSum = prefixSum[idx] - (i > 0 ? prefixSum[i - 1] : 0);
//             int rightSum = prefixSum[j] - prefixSum[idx];
//             int x1 = i, y1 = idx, x2 = idx + 2, y2 = j;

//             if (leftSum == rightSum) {
//                 x2 = idx + 1;
//             }else{
//                 rightSum=prefixSum[j] - prefixSum[idx+1];
//             }

//             int y=max(leftSum + solve(x1, y1), rightSum + solve(x2, y2));
//             cout<<i<<" "<<j<<" "<<y<<endl;

//             return y;
//         }

//         int x=prefixSum[j]-prefixSum[i]+solve(i+1,j);
//        cout<<i<<" "<<j<<" "<<x<<endl;

//         return x;
//     }
//     int stoneGameV(vector<int>& stoneValue) {
//         int n = stoneValue.size();
//         memset(t,-1,sizeof(t));

//         prefixSum.assign(n, 0);
//         prefixSum[0] = stoneValue[0];

//         for (int i = 1; i < n; i++) {
//             prefixSum[i] = prefixSum[i - 1] + stoneValue[i];
//         }

//         return solve(0, n - 1);
//     }
// };

//----- 

// Approach-1 - Recursion + Memo
// T.C : O(n^3)
// S.C : O(n^2)
class Solution
{
public:
    int t[501][501];
    int solve(int l, int r, vector<int> &cumSum)
    {
        if (l >= r)
        {
            return 0; // Zero score. No further division possible
        }

        if (t[l][r] != -1)
        {
            return t[l][r];
        }

        int score = 0;
        for (int mid = l; mid <= r - 1; mid++)
        {
            int leftSum = cumSum[mid] - (l - 1 >= 0 ? cumSum[l - 1] : 0); //[l..mid]
            int rightSum = cumSum[r] - cumSum[mid];                       // mid+1, r

            if (leftSum < rightSum)
            {
                score = max(score, leftSum + solve(l, mid, cumSum));
            }
            else if (leftSum > rightSum)
            {
                score = max(score, rightSum + solve(mid + 1, r, cumSum));
            }
            else
            {
                score = max({score, leftSum + solve(l, mid, cumSum), rightSum + solve(mid + 1, r, cumSum)});
            }
        }

        return t[l][r] = score;
    }

    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = stoneValue[0];
        for (int i = 1; i < n; i++)
        {
            cumSum[i] = cumSum[i - 1] + stoneValue[i];
        }

        memset(t, -1, sizeof(t));
        return solve(0, n - 1, cumSum);
    }
};
