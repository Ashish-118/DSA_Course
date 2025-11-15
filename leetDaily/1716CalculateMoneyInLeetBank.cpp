class Solution
{
public:
    int totalMoney(int n)
    {
        int ans = 0;

        int x = n / 7;

        ans += (28 * x + (x * (2 * (0) + (x - 1) * 7)) / 2);

        int r = n % 7;

        ans += (r * (2 * (x + 1) + (r - 1))) / 2; // sum of ap

        return ans;
    }
}; // time O(1) space O(1)