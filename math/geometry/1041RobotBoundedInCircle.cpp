class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int dirX = 0, dirY = 1; // facing north
        int x = 0, y = 0;

        for (char d : instructions)
        {
            if (d == 'G')
            {
                x += dirX;
                y += dirY;
            }
            else if (d == 'L')
            {
                int newDirX = -dirY;
                int newDirY = dirX;
                dirX = newDirX;
                dirY = newDirY;
            }
            else
            { // 'R'
                int newDirX = dirY;
                int newDirY = -dirX;
                dirX = newDirX;
                dirY = newDirY;
            }
        }

               return (x == 0 && y == 0) || !(dirX == 0 && dirY == 1);
    }
};
