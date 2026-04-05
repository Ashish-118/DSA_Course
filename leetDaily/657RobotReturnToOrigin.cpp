class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;

        for (auto d : moves)
        {
            if (d == 'D')
                y--;

            else if (d == 'U')
                y++;
            else if (d == 'R')
                x++;
            else if (d == 'L')
                x--;
        }

        return x == 0 && y == 0;
    }
};