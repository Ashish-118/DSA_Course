// class Solution
// {
// public:
//     bool isSafe(int val, int r, int c, vector<vector<char>> &board, vector<map<int, bool>> &m)
//     {
//         bool row = false;
//         if (!m[r][val])
//         {
//             row = true;
//         }
//         bool col = true;
//         for (int i = 0; i < 9; i++)
//         {
//             if (board[i][c] == ('0' + val))
//             {
//                 col = false;
//             }
//         }

//         bool check = true;

//         if (0 <= c && c <= 2)
//         {
//             c = 0;
//             if (0 <= r && r <= 2)
//                 r = 0;
//             else if (3 <= r && r <= 5)
//                 r = 3;
//             else
//                 r = 6;
//         }
//         else if (3 <= c && c <= 5)
//         {
//             c = 3;
//             if (0 <= r && r <= 2)
//                 r = 0;
//             else if (3 <= r && r <= 5)
//                 r = 3;
//             else
//                 r = 6;
//         }
//         else
//         {
//             c = 6;
//             if (0 <= r && r <= 2)
//                 r = 0;
//             else if (3 <= r && r <= 5)
//                 r = 3;
//             else
//                 r = 6;
//         }

//         for (int i = r; i < r + 3; i++)
//         {
//             for (int j = c; j < c + 3; j++)
//             {
//                 if (board[i][j] == ('0' + val))
//                 {
//                     check = false;
//                     break;
//                 }
//             }
//             if (!check)
//                 break;
//         }
//         return check && row && col;
//     }

//     void solve(vector<vector<char>> &board, vector<map<int, bool>> &m, int r, int c, bool &check)
//     {
//         if (r == 8 && c == 9)
//         {
//             check = false;
//             return;
//         }
//         else if (c == 9)
//         {
//             r++;
//             c = 0;
//         }

//         if (board[r][c] == '.')
//         {
//             for (int i = 1; i <= 9; i++)
//             { // Change loop to start from 1, as Sudoku numbers are 1-9
//                 if (isSafe(i, r, c, board, m) && check)
//                 {
//                     board[r][c] = '0' + i;
//                     m[r][i] = true;
//                     solve(board, m, r, c + 1, check);
//                     if (check)
//                     {
//                         board[r][c] = '.';
//                         m[r][i] = false;
//                     }
//                 }
//             }
//         }
//         else
//         {
//             solve(board, m, r, c + 1, check);
//         }
//     }

//     void solveSudoku(vector<vector<char>> &board)
//     {
//         vector<map<int, bool>> m(9); // Initialize with size 9
//         for (int i = 0; i < 9; i++)
//         {
//             for (int j = 0; j < 9; j++)
//             {
//                 if (board[i][j] != '.')
//                 {
//                     int n = board[i][j] - '0';
//                     m[i][n] = true;
//                 }
//             }
//         }
//         bool check = true;
//         solve(board, m, 0, 0, check);
//     }
// };

//---- optimised

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
