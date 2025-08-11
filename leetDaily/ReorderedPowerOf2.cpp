
// approach 1
class Solution
{
public:
    string fn(int n)
    {
        string num = to_string(n);
        sort(begin(num), end(num));
        return num;
    }
    bool reorderedPowerOf2(int n)
    {
        string num = to_string(n);
        sort(begin(num), end(num));

        for (int p = 0; p < 31; p++)
        {
            if (num == fn(1 << p))
            {
                return true;
            }
        }

        return false;
    }
};

// approach 2

class Solution
{
public:
    unordered_set<string> st;
    void buildSet()
    {
        // 2^p from p = 0 to 29
        // convert to string
        // sort it
        // store it in st
        for (int p = 0; p <= 29; p++)
        {
            string s = to_string(1 << p);
            sort(begin(s), end(s));
            st.insert(s);
        }
    }

    bool reorderedPowerOf2(int n)
    {
        if (st.empty())
        {
            buildSet();
        }

        string s = to_string(n);
        sort(begin(s), end(s));

        return st.count(s);
    }
};

// approach 3

class Solution
{
public:
    vector<int> getVectorCountFormat(int n)
    {
        vector<int> vec(10, 0);

        // 256
        // 256/10 = 25
        while (n)
        {
            vec[n % 10]++;
            n /= 10;
        }

        return vec;
    }

    bool reorderedPowerOf2(int n)
    {
        vector<int> input = getVectorCountFormat(n);

        for (int p = 0; p <= 29; p++)
        {
            if (input == getVectorCountFormat(1 << p))
            {
                return true;
            }
        }

        return false;
    }
};

// approach 4
class Solution
{
public:
    int getVectorCountFormat(int n)
    {
        int num = 0;

        // 256
        // 256/10 = 25
        while (n)
        {
            num += pow(10, n % 10);
            n /= 10;
        }

        return num;
    }

    bool reorderedPowerOf2(int n)
    {
        int input = getVectorCountFormat(n);

        for (int p = 0; p <= 29; p++)
        {
            if (input == getVectorCountFormat(1 << p))
            {
                return true;
            }
        }

        return false;
    }
};
