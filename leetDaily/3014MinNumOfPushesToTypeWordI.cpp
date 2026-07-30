class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.length();
        int timesCoveringAll_8_keys = n / 8;
        int rem = n % 8;

        return 8 * ((timesCoveringAll_8_keys * (timesCoveringAll_8_keys + 1)) / 2) + (timesCoveringAll_8_keys + 1) * rem;
    }
};