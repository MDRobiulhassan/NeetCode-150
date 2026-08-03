#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rows, cols;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int bfs(vector<vector<int>> &grid, int r, int c)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;

        int area = 1;

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1)
                {

                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                    area++;
                }
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();

        int ans = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                if (grid[i][j] == 1)
                {
                    ans = max(ans, bfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};