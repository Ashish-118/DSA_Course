class Solution
{
public:
    int maximum69Number(int num)
    {
        string n = to_string(num);
        size_t i = n.find('6');
        if (i != string::npos)
        {
            n.replace(i, 1, "9");
        }
        return stoi(n);
    }
};