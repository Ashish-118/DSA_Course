class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));

        std::function<int(int, int)> find_gcd = [&](int a, int b)
        {
            if (b == 0)
                return a;
            return find_gcd(b, a % b);
        };

        return find_gcd(mini, maxi);
    }
};