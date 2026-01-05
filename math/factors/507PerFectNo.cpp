class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        set<int> st;
        for (int i = 1; i * i <= num; i++)
        {
            if ((num % i) == 0)
            {
                int div2 = num / i;

                if (i != num)
                    st.insert(i);

                if (div2 != num)
                    st.insert(div2);
            }
        }
        int sum = accumulate(st.begin(), st.end(), 0);
        cout << sum << endl;
        return sum == num;
    }
};

// without extra space

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num <= 1)
            return false;

        int sum = 1; // 1 is always a proper divisor

        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                sum += i;

                if (i != num / i)
                { // avoid double-counting square root
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};
