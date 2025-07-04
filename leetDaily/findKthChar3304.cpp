class Solution
{
public:
    char kthCharacter(int k)
    {
        string ans = "a";

        while (ans.length() < k)
        {
            string add = "";
            for (char x : ans)
            {
                if (x == 'z')
                    add += 'a';
                else
                    add += (x + 1);
            }
            ans += add;
        }
        return ans[k - 1];
    }
}; // O(k) solution, but we can do better

//
char kthCharacter(int k)
{
    return 'a' + __builtin_popcount(k - 1);
} // O(log k) solution using bit manipulation