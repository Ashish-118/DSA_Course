class Robot
{
public:
    int x, y;
    int n, m;
    unordered_map<string, string> mp;
    string dir = "South";
    bool check = true;

    Robot(int width, int height)
    {
        x = 0;
        y = 0;
        m = width;
        n = height;
        mp["East"] = "North";
        mp["North"] = "West";
        mp["West"] = "South";
        mp["South"] = "East";
    }

    void step(int num)
    {
        check = false;
        int cycle = 2 * m + 2 * n - 4;
        int rem = num % cycle;

        while (rem > 0)
        {
            if (x == 0 && y == 0 || x == 0 && y == n - 1 ||
                y == n - 1 && x == m - 1 || y == 0 && x == m - 1)
            {
                dir = mp[dir];
            }

            int steps = 0;

            if (dir == "East")
            {
                steps = min(m - 1 - x, rem);
                x += steps;
            }
            else if (dir == "North")
            {
                steps = min(n - 1 - y, rem);
                y += steps;
            }
            else if (dir == "West")
            {
                steps = min(x, rem);
                x -= steps;
            }
            else if (dir == "South")
            {
                steps = min(y, rem);
                y -= steps;
            }

            rem -= steps;
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir()
    {
        if (check)
            return "East";
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */