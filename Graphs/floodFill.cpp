class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<pair<int, int>> dr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int r = image.size();
        int c = image[0].size();
        int baseColor = image[sr][sc];
        while (!q.empty())
        {

            pair<int, int> front = q.front();
            q.pop();

            if (image[front.first][front.second] != color)
            {
                image[front.first][front.second] = color;
                for (auto x : dr)
                {
                    int row = front.first + x.first;
                    int col = front.second + x.second;
                    if ((row) < r && (col) < c && (row) >= 0 && (col) >= 0 && image[row][col] == baseColor)
                    {
                        q.push({row, col});
                    }
                }
            }
        }
        return image;
    }
};