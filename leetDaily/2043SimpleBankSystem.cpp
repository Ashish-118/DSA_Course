class Bank
{
public:
    vector<long long> B;
    int accounts;
    Bank(vector<long long> &balance)
    {
        B = balance;
        accounts = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (1 <= account1 && account1 <= accounts && 1 <= account2 && account2 <= accounts && money <= B[account1 - 1])
        {
            B[account1 - 1] -= money;
            B[account2 - 1] += money;
            return true;
        }
        else
            return false;
    }

    bool deposit(int account, long long money)
    {
        if (1 <= account && account <= accounts)
        {
            B[account - 1] += money;
            return true;
        }
        else
            return false;
    }

    bool withdraw(int account, long long money)
    {
        if (1 <= account && account <= accounts && money <= B[account - 1])
        {
            B[account - 1] -= money;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */