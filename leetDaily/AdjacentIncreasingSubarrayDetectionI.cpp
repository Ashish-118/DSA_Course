// Approach-2 (Optimal : Loop and keep checking)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                currRun++;
            }
            else
            { // increaseing order break hogaya yaha par
                prevRun = currRun;
                currRun = 1;
            }

            if (currRun >= 2 * k)
            {
                // we can accomodate two subarrays in it length. >= k
                return true;
            }

            if (min(currRun, prevRun) >= k)
            {
                return true;
            }
        }

        return false;
    }
};
}
;