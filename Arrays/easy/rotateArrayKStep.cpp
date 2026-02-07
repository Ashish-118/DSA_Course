class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        // rotate the array to the right by k steps, where k is non-negative.
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());
    }
};

// to rotate the array to the left by k steps, we can follow a similar approach:

// void rotateLeft(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     k %= n;

//     reverse(nums.begin(), nums.begin() + k);
//     reverse(nums.begin() + k, nums.end());
//     reverse(nums.begin(), nums.end());
// }
