class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        string num = "";
        for (auto x : digits)
            num += (x + '0');

        vector<int> ans;
        int len = num.length();
        int carry = 1;

        for (int i = len - 1; i >= 0; i--)
        {
            int sum = carry + num[i] - '0';
            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry == 1)
            ans.push_back(1);
        reverse(begin(ans), end(ans));
        return ans;
    }
}; // time complexity: O(n)