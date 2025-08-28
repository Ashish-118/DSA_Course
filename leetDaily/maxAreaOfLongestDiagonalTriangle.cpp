class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int MaxArea = 0;
        int longestDiagonal = 0;
        for (auto &x : dimensions)
        {
            int l = x[0], w = x[1];
            int currLenDiagnoal = (pow(l, 2) + pow(w, 2));

            if (longestDiagonal < currLenDiagnoal)
            {
                longestDiagonal = currLenDiagnoal;
                MaxArea = l * w;
            }
            else if (longestDiagonal == currLenDiagnoal)
            {
                MaxArea = max(MaxArea, l * w);
            }
        }
        return MaxArea;
    }
};