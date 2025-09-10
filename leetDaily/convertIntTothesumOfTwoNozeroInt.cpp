class Solution
{
public:
    bool check(int num)
    {
        string str = to_string(num);
        return str.find('0') == string::npos;
    }
    vector<int> getNoZeroIntegers(int n)
    {

        for (int i = 1; i < n; i++)
        {
            int rem = n - i;

            if (check(i) && check(rem))
            {
                return {i, rem};
            }
        }
        return {};
    }
};