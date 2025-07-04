//  is wrong logically little bit

// class Solution
// {
// public:
//     void loop(string &s, char m1, char m2, char t, int &k)
//     {
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (k == 0)
//                 break;

//             if (s[i] == m1 || s[i] == m2)
//             {
//                 if (s[i] != t)
//                 {
//                     s[i] = t;
//                     k--;
//                 }
//             }
//         }
//     }
//     int maxDistance(string s, int k)
//     {
//         int countN = count(s.begin(), s.end(), 'N');
//         int countS = count(s.begin(), s.end(), 'S');
//         int countW = count(s.begin(), s.end(), 'W');
//         int countE = count(s.begin(), s.end(), 'E');

//         char Y = (countN >= countS ? 'N' : 'S');
//         char X = (countW >= countE ? 'W' : 'E');
//         int RepX = max(countW, countE);
//         int RepY = max(countN, countS);

//         if (RepY >= RepX)
//         {
//             loop(s, 'N', 'S', Y, k);
//             loop(s, 'E', 'W', X, k);
//         }
//         else
//         {
//             loop(s, 'E', 'W', X, k);
//             loop(s, 'N', 'S', Y, k);
//         }

//         int countX = 0;
//         int countY = 0;
//         int maxi = 0;

//         for (int i = 0; i < s.length(); i++)
//         {
//             if (s[i] == 'N')
//                 countX++;
//             else if (s[i] == 'S')
//                 countX--;
//             else if (s[i] == 'E')
//                 countY++;
//             else if (s[i] == 'W')
//                 countY--;
//             int dist = abs(countX - 0) + abs(countY - 0);
//             maxi = max(maxi, dist);
//         }

//         return maxi;
//     }
// };

// correct code

class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
            case 'N':
                latitude++;
                break;
            case 'S':
                latitude--;
                break;
            case 'E':
                longitude++;
                break;
            case 'W':
                longitude--;
                break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};