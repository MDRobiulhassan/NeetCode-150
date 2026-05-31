#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};