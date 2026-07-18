class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*max_element(begin(nums),end(nums)),*min_element(begin(nums),end(nums)));
    }
};