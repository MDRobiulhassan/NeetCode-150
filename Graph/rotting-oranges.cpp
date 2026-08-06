#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        int time = 0;
        while (!q.empty() && fresh > 0)
        {
            int size = q.size();

            while (size--)
            {
                auto [row, col] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 1)
                    {

                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            time++;
        }

        return (fresh == 0) ? time : -1;
    }
};