// class Solution {
//     public int[] countBits(int n) {
//         int[] ans = new int[n + 1];

//         for (int i = 1; i <= n; i++) {
//             ans[i] = ans[i >> 1] + (i & 1);
//         }

//         return ans;
//     }
// }


class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            ans[i] = Integer.bitCount(i);
        }

        return ans;
    }
}


// c++ solution 

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> sol(n + 1);
        
//         for(int i = 0; i <= n; i++){
//             sol[i] = __builtin_popcount(i);
//         }
        
//         return sol;
//     }
// };