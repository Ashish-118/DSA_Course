// class Solution
// {
// public:
//     int earliest(int n, int f, int s)
//     {
//         map<int, bool> m;

//         for (int i = 1; i <= n; i++)
//         {
//             m[i] = false;
//         }

//         bool loop = true;
//         int round = 0;
//         m[f] = true;
//         m[s] = true;

//         while (loop)
//         {
//             vector<int> v;

//             for (auto x : m)
//             {
//                 if (!x.second && round == 0)
//                     v.push_back(x.first);
//                 else if (x.second)
//                     v.push_back(x.first);
//             }

//             int len = v.size();
//             for (int i = 0; i < len / 2; i++)
//             {

//                 if (i == 0)
//                 {
//                     m[v[(len - 1) - i]] = true;
//                 }
//                 else if ((v[i] == f && v[(len - 1) - i] == s) || (v[i] == s && v[(len - 1) - i] == f))
//                 {

//                     loop = false;
//                     break;
//                 }
//                 else
//                 {
//                     if (!m[v[i]] && !m[v[(len - 1) - i]])
//                         m[v[i]] = true;
//                 }
//             }
//             if (len % 2 != 0 && len > 0)
//                 m[v[len / 2]] = true;
//             round++;
//         }
//         return round;
//     }

//     int latest(int n, int f, int s)
//     {
//         map<int, bool> m;

//         for (int i = 1; i <= n; i++)
//         {
//             m[i] = false;
//         }

//         bool loop = true;
//         int round = 0;
//         m[f] = true;
//         m[s] = true;

//         while (loop)
//         {
//             vector<int> v;

//             for (auto x : m)
//             {
//                 if (!x.second && round == 0)
//                     v.push_back(x.first);
//                 else if (x.second)
//                     v.push_back(x.first);
//             }
//             int len = v.size();
//             for (int i = 0; i < len / 2; i++)
//             {

//                 if (i == 0)
//                 {
//                     m[v[i]] = true;
//                 }
//                 else if ((v[i] == f && v[(len - 1) - i] == s) || (v[i] == s && v[(len - 1) - i] == f))
//                 {

//                     loop = false;
//                     break;
//                 }
//                 else
//                 {
//                     if (!m[v[i]] && !m[v[(len - 1) - i]])
//                         m[v[i]] = true;
//                 }
//             }
//             if (len % 2 != 0 && len > 0)
//                 m[v[len / 2]] = true;
//             round++;
//             cout << "round " << round << endl;
//         }
//         return round;
//     }

//     vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
//     {
//         vector<int> ans;
//         ans.push_back(earliest(n, firstPlayer, secondPlayer));
//         ans.push_back(latest(n, firstPlayer, secondPlayer));
//         return ans;
//     }
// };