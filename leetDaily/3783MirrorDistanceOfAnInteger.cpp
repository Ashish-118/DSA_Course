class Solution
{
public:
    int mirrorDistance(int n)
    {
        string num = to_string(n);
        reverse(begin(num), end(num));
        int rev_n = stoi(num);
        return abs(rev_n - n);
    }
};