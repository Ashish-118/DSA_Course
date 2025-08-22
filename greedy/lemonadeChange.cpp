class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int twenty = 0;
        int ten = 0;
        int five = 0;

        for (auto &bill : bills)
        {
            int toReturn = bill - 5;
            int tw = (toReturn / 20 <= twenty ? (toReturn / 20) : twenty);
            twenty -= tw;
            toReturn -= (tw * 20);

            int te = (toReturn / 10 <= ten ? (toReturn / 10) : ten);
            ten -= te;
            toReturn -= (te * 10);

            int fi = (toReturn / 5 <= five ? (toReturn / 5) : twenty);
            five -= fi;
            toReturn -= (fi * 5);

            if (bill == 5)
                five++;
            else if (bill == 20)
                twenty++;
            else
                ten++;

            if (toReturn != 0)
                return false;
        }
        return true;
    }
};