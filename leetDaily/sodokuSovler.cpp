class Solution
{
public:
    bool isSafe(int val, int r, int c, vector<vector<char>> &board, vector<vector<bool>> &rowCheck, vector<vector<bool>> &colCheck, vector<vector<bool>> &boxCheck)
    {
        int boxIndex = (r / 3) * 3 + (c / 3);
        return !rowCheck[r][val] && !colCheck[c][val] && !boxCheck[boxIndex][val];
    }

    bool solve(vector<vector<char>> &board, vector<vector<bool>> &rowCheck, vector<vector<bool>> &colCheck, vector<vector<bool>> &boxCheck, int r, int c)
    {
        if (r == 9)
            return true; // Successfully filled the board
        if (c == 9)
            return solve(board, rowCheck, colCheck, boxCheck, r + 1, 0); // Move to the next row

        if (board[r][c] != '.')
            return solve(board, rowCheck, colCheck, boxCheck, r, c + 1); // Skip filled cells

        for (int i = 1; i <= 9; i++)
        {
            int boxIndex = (r / 3) * 3 + (c / 3);

            if (isSafe(i, r, c, board, rowCheck, colCheck, boxCheck))
            {
                board[r][c] = '0' + i;
                rowCheck[r][i] = colCheck[c][i] = boxCheck[boxIndex][i] = true;

                if (solve(board, rowCheck, colCheck, boxCheck, r, c + 1))
                    return true; // If solution found, return

                board[r][c] = '.'; // Backtrack
                rowCheck[r][i] = colCheck[c][i] = boxCheck[boxIndex][i] = false;
            }
        }

        return false; // No valid placement found
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> rowCheck(9, vector<bool>(10, false));
        vector<vector<bool>> colCheck(9, vector<bool>(10, false));
        vector<vector<bool>> boxCheck(9, vector<bool>(10, false));

        // Initialize check arrays
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    rowCheck[i][num] = colCheck[j][num] = boxCheck[boxIndex][num] = true;
                }
            }
        }

        solve(board, rowCheck, colCheck, boxCheck, 0, 0);
    }
};
