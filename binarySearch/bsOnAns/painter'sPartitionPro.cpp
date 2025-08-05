int poss(vector<int> &nums, int maxSum)
{
    int prev = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if ((prev + nums[i]) <= maxSum)
        {
            prev += nums[i];
        }
        else
        {
            count++;
            prev = nums[i];
        }
    }
    return count;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = *max_element(begin(boards), end(boards));
    int e = accumulate(begin(boards), end(boards), 0);
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int val = poss(boards, mid);
        if (val <= k)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}