class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars,
                               vector<int> &vBars)
    {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int CosecutiveHorizontalLines = 0;
        int CosecutiveVerticalLines = 0;

        int l1 = hBars.size(), l2 = vBars.size();
        int ans = 1;
        int prev = -1;
        for (int i = 0; i < l1; i++)
        {
            if ((hBars[i] - prev) == 1)
            {
                ans++;
            }
            if ((hBars[i] - prev) != 1)
            {

                ans = 1;
            }

            CosecutiveHorizontalLines = max(CosecutiveHorizontalLines, ans);
            prev = hBars[i];
        }

        prev = -1;
        ans = 1;
        for (int i = 0; i < l2; i++)
        {
            if ((vBars[i] - prev) == 1)
            {
                ans++;
            }
            if ((vBars[i] - prev) != 1)
            {

                ans = 1;
            }

            CosecutiveVerticalLines = max(CosecutiveVerticalLines, ans);
            prev = vBars[i];
        }

        int mini = min(CosecutiveVerticalLines, CosecutiveHorizontalLines);

        return (mini + 1) * (mini + 1);
    }
};