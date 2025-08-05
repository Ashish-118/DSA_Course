#define mod 1000000009
class Solution
{
public:
    int mul(long long a, long long b)
    {
        return ((a % mod) * (b % mod)) % mod;
    }
    int sum(int a, int b)
    {
        return ((a % mod) + (b % mod)) % mod;
    }
    long long nCr(int n, int r)
    {
        if (r > n)
            return 0;
        if (r == 0 || r == n)
            return 1;

        long long res = 1;

        if (r > n - r)
            r = n - r;

        for (int i = 0; i < r; ++i)
        {
            res = mul(res, n - i);
            res /= (i + 1);
        }

        return res;
    }
    int countTrapezoids(vector<vector<int>> &points)
    {
        map<int, int> m;
        for (auto &i : points)
        {
            int x = i[0];
            int y = i[1];
            m[y]++;
        }

        vector<int> v;

        for (auto &x : m)
        {
            v.push_back(x.second);
        }

        int index = 0;
        int top = 1;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != 1)
            {
                index = i;
                top = nCr(v[i], 2);
                break;
            }
        }

        int ans = 0;
        for (int i = index + 1; i < v.size(); i++)
        {
            int ways = nCr(v[i], 2);
            ans = sum(ans, mul(ways, top));
            top = sum(ways, top);
        }

        return ans;

        // for(int i=0; i<v.size(); i++){
        //     if(v[i]>=2){
        //         for(int j=i+1; j<v.size(); j++){
        //         if(v[j]>=2 ){
        //             ans=sum(ans,mul(nCr(v[i],2),nCr(v[j],2)));
        //         }
        //     }
        //     }

        // }

        return ans;
    }
};
// passed 549/554

/// optimized code

class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int MOD = 1000000007;
        unordered_map<int, long long> groups;
        for (auto &point : points)
            groups[point[1]]++;
        long long res = 0, total = 0;
        for (auto &group : groups)
        {
            long long lines = group.second * (group.second - 1) / 2;
            res = (res + total * lines) % MOD;
            total = (total + lines) % MOD;
        }
        return (int)res;
    }
};

// Logic same