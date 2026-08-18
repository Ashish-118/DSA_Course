class Solution
{
public
    int largestInteger(int[] nums, int k)
    {
        int n = nums.length;

        int ans = -1;

        HashMap<Integer, Integer> f = new HashMap<>();

        for (int x : nums)
        {
            f.put(x, f.getOrDefault(x, 0) + 1);
        }

        if (f.get(nums[0]) == 1)
        {
            ans = nums[0];
        }
        if (f.get(nums[n - 1]) == 1)
        {
            ans = Math.max(nums[n - 1], ans);
        }

        int maxi = Integer.MIN_VALUE;

        if (k == 1)
        {
            for (int x : nums)
            {
                if (f.get(x) == 1)
                {
                    maxi = Math.max(maxi, x);
                }
            }
        }
        if (k == n)
        {
            for (int x : nums)
            {

                maxi = Math.max(maxi, x);
            }
        }

        ans = Math.max(ans, maxi);

        return ans;
    }
}