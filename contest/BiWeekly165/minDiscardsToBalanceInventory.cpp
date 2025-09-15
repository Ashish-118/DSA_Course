class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        int l = 0, r = -1;
        unordered_map<int, int> mp;
        int disgard = 0;
        int n = arrivals.size();
        vector<bool> kept(n, false);

        for (int i = 0; i < arrivals.size(); i++)
        {

            if ((r - l + 1) < w)
            {

                mp[arrivals[i]]++;

                if (mp[arrivals[i]] > m)
                {
                    mp[arrivals[i]]--;
                    disgard++;
                }
                else
                {
                    kept[i] = true;
                }
                r = i;
            }
            else
            {

                if (kept[l])
                    mp[arrivals[l]]--;
                l++;
                r = i;

                mp[arrivals[r]]++;

                if (mp[arrivals[r]] > m)
                {
                    mp[arrivals[r]]--;
                    disgard++;
                }
                else
                {
                    kept[i] = true;
                }
            }
        }

        return disgard;
    }
};