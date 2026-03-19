class Solution
{
public:
    int t[101][201];

    int solve(int i, int M, vector<int> &piles, int n)
    {
        if (i >= n)
            return 0;
        if (t[i][M] != -1)
            return t[i][M];
        int ans = 0;
        int stones = 0;

        for (int k = 1; k <= 2 * M; k++)
        {
            if (i + k - 1 >= n)
                break;

            stones += piles[i + k - 1];

            int M1 = max(M, k);
            int MinMaxi = INT_MAX;
            for (int x = 1; x <= 2 * M1; x++)
            {

                MinMaxi = min(MinMaxi, solve(i + k + x, max(x, M1), piles, n));
            }

            ans = max(ans, stones + MinMaxi);
        }

        return t[i][M] = ans;
    }
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();

        memset(t, -1, sizeof(t));

        return solve(0, 1, piles, n);
    }
};

// optimal recurr + memo

// Recursion + Memo
// T.C : O(n^3)
// S.C : O(n^3)
class Solution
{
public:
    int n;
    int t[2][101][101]; // t[2][n+1][n+1] - 2*(n+1)*(n+1) ~n^2 * n ~ O(n^3)
    int solveForAlice(vector<int> &piles, int person, int i, int M)
    {

        if (i >= n)
            return 0;

        if (t[person][i][M] != -1)
            return t[person][i][M];

        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++)
        {

            stones += piles[i + x - 1];

            if (person == 1)
            { // Alice
                result = max(result, stones + solveForAlice(piles, 0, i + x, max(M, x)));
            }
            else
            { // Bob
                result = min(result, solveForAlice(piles, 1, i + x, max(M, x)));
            }
        }

        return t[person][i][M] = result;
    }

    int stoneGameII(vector<int> &piles)
    {
        n = piles.size();

        memset(t, -1, sizeof(t));

        return solveForAlice(piles, 1, 0, 1);
    }
};

// bottom up approach

// Recursion + Memo
// T.C : O(n^3)
// S.C : O(n^3)
class Solution
{
public:
    int n;
    int t[2][101][101];

    int solveForAlice(vector<int> &piles, int person, int i, int M)
    {

        if (i >= n)
            return 0;

        if (t[person][i][M] != -1)
            return t[person][i][M];

        int result = (person == 1) ? -1 : INT_MAX;

        int stones = 0;

        for (int x = 1; x <= min(2 * M, n - i); x++)
        {

            stones += piles[i + x - 1];

            if (person == 1)
            { // Alice
                result = max(
                    result, stones + solveForAlice(piles, 0, i + x, max(M, x)));
            }
            else
            { // Bob
                result = min(result, solveForAlice(piles, 1, i + x, max(M, x)));
            }
        }

        return t[person][i][M] = result;
    }

    int stoneGameII(vector<int> &piles)
    {
        n = piles.size();

        memset(t, 0, sizeof(t));

        // return solveForAlice(piles, 1, 0, 1);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int M = 1; M <= n; M++)
            {
                for (int person = 0; person < 2; person++)
                {
                    int result = (person == 1) ? -1 : INT_MAX;

                    int stones = 0;

                    for (int x = 1; x <= min(2 * M, n - i); x++)
                    {

                        stones += piles[i + x - 1];

                        if (person == 1)
                        { // Alice
                            result =
                                max(result, stones + t[0][i + x][max(M, x)]);
                        }
                        else
                        { // Bob
                            result = min(result, t[1][i + x][max(M, x)]);
                        }
                    }

                    t[person][i][M] = result;
                }
            }
        }

        return t[1][0][1];
    }
};
