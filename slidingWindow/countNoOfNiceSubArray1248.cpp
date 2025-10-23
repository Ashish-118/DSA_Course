class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int ans = 0;

        int countOdd = 0;
        int l = 0, r = 0, n = nums.size();

        while (r < n)
        {
            if (nums[r] & 1)
                countOdd++;

            if (countOdd == k)
            {
                int evenLeft = 0, evenRight = 0;
                while (l < n && !(nums[l] & 1))
                {
                    evenLeft++;
                    l++;
                }
                r++;
                while (r < n && !(nums[r] & 1))
                {
                    evenRight++;
                    r++;
                }

                ans += (evenLeft * evenRight + evenLeft + evenRight + 1);
                l++;
                countOdd--;
            }
            else
            {
                r++;
            }
        }

        return ans;
    }
}; // time complexity : O(n), space complexity : O(1)