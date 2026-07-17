#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int i, vector<int> &nums, vector<vector<int>> &ans,
                  vector<int> &list)
    {
        if (i >= nums.size())
        {
            ans.push_back(list);
            return;
        }

        list.push_back(nums[i]);
        generate(i + 1, nums, ans, list);
        list.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        generate(i + 1, nums, ans, list);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> list;
        sort(nums.begin(), nums.end());
        generate(0, nums, ans, list);
        return ans;
    }
};