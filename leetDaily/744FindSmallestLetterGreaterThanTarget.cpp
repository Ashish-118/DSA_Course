class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        char ans = letters[0];

        auto find =
            upper_bound(begin(letters), end(letters), target) - letters.begin();

        if (find < letters.size())
        {
            ans = letters[find];
        }

        return ans;
    }
};