class Solution {
public:
    int mod = 1000000007;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();

        int m = 0, r = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < a) {
                ans = (ans + m + r) % mod;
            } else if (nums[i] <= b) {
                ans = (ans + r) % mod;
                m++;
            } else {
                r++;
            }
        }

        return ans;
    }
};