#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row, col;

    bool dfs(vector<vector<char>> &board, string &word, int r, int c, int i)
    {

        if (i == word.size())
            return true;

        if (r < 0 || c < 0 || r >= row || c >= col || board[r][c] == '#' ||
            board[r][c] != word[i])
            return false;

        board[r][c] = '#';

        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);

        board[r][c] = word[i];

        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        row = board.size();
        col = board[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};