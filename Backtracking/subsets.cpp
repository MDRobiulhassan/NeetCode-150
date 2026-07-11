#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int i, vector<int> &nums, vector<vector<int>> &res,
                  vector<int> &subset)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        generate(i + 1, nums, res, subset);

        subset.pop_back();
        generate(i + 1, nums, res, subset);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> subset;

        generate(0, nums, res, subset);
        return res;
    }
};