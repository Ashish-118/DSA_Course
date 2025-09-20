class Spreadsheet
{
public:
    vector<vector<int>> v;

    Spreadsheet(int rows)
    {
        v = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        v[row - 1][col] = value;
    }

    void resetCell(string cell)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        v[row - 1][col] = 0;
    }

    int getValue(string formula)
    {
        int i = 0;
        string str1 = "";
        for (i; i < formula.length(); i++)
        {
            if (formula[i] == '+')
                break;
            str1 += formula[i];
        }

        str1 = str1.substr(1);
        string str2 = formula.substr(i + 1);
        int ans = 0;

        if (isalpha(str1[0]))
        {

            int col = str1[0] - 'A';

            int row = stoi(str1.substr(1));

            ans += v[row - 1][col];
        }
        else
        {
            ans += stoi(str1);
        }

        if (isalpha(str2[0]))
        {

            int col = str2[0] - 'A';
            int row = stoi(str2.substr(1));

            ans += v[row - 1][col];
        }
        else
        {
            ans += stoi(str2);
        }

        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */