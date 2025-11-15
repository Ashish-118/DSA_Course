class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {

        int score = 0;

        sort(begin(tokens), end(tokens));

        int i = 0, j = tokens.size() - 1;

        while (i <= j)
        {
            if (power >= tokens[i])
            {
                score++;
                power -= tokens[i];
                i++;
            }
            else
            {
                if (score > 0 && i != j)
                {
                    score--;
                    power += tokens[j];
                    j--;
                }
                else
                    break;
            }
        }

        return score;
    }
};