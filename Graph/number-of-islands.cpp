#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rows, cols;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

private:
    void bfs(vector<vector<char>> &grid, int r, int c)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    grid[nr][nc] == '1')
                {
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        int island = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    island++;
                    bfs(grid, r, c);
                }
            }
        }
        return island;
    }
};