class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_ = 0;
        for (auto x : nums) {
            xor_ ^= x;
        }

        int allZero = *max_element(begin(nums), end(nums));
        if (allZero == 0)
            return 0;

        return xor_ ? nums.size() : nums.size() - 1;
    }
};