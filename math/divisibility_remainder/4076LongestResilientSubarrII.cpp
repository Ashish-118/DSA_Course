class Solution
{
public:
    int resilientSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();

        int temp = -1;
        int ans = 1;

        int left = 0;
        int rem = 0;

        for (int right = 0; right < n; right++)
        {

            if (temp != (nums[right] % k))
            {
                temp = (nums[right] % k);
                left = right;
                rem = temp;
            }
            else
            {

                rem = (rem + nums[right] % k) % k;

                if (rem == temp)
                {
                    // cout<<" hi "<<endl;
                    ans = max(ans, right - left + 1);
                }

                // cout<<" ans "<<ans<<endl;
            }

            // cout<<" left "<<left<<"right "<<right<<" rem "<<rem<<" temp "<<temp<<endl;
        }

        return ans;
    }
};