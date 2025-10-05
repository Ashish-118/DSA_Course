class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0;
        int n = version1.size();
        int m = version2.size();
        while (i < n && j < m)
        {
            int x = i;
            int y = j;

            while (i < n && version1[i] != '.')
            {
                i++;
            }
            while (j < m && version2[j] != '.')
            {
                j++;
            }

            int v1 = stoi(version1.substr(x, i - x));
            int v2 = stoi(version2.substr(y, j - y));
            if (v1 < v2)
                return -1;
            else if (v1 > v2)
                return 1;

            i++;
            j++;
        }

        while (i < n)
        {
            int x = i;

            while (i < n && version1[i] != '.')
            {
                i++;
            }

            int v1 = stoi(version1.substr(x, i - x));
            if (v1 < 0)
                return -1;
            else if (v1 > 0)
                return 1;

            i++;
        }

        cout << j << endl;
        while (j < m)
        {
            int y = j;

            while (j < m && version2[j] != '.')
            {
                j++;
            }
            cout << j << endl;
            int v2 = stoi(version2.substr(y, j - y));
            cout << v2 << endl;
            if (v2 < 0)
                return 1;
            else if (v2 > 0)
                return -1;

            j++;
        }

        return 0;
    }
};