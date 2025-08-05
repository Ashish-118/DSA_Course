bool check(vector<int> &stalls, int k, int dist)
{

    int cnt = 1;
    int prev = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {

        if (stalls[i] - prev >= dist)
        {
            prev = stalls[i];
            cnt++;
        }
    }

    return (cnt >= k);
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(begin(stalls), end(stalls));
    int s = 0, e = stalls.back() - stalls[0];
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (check(stalls, k, mid))
        {
            s = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}