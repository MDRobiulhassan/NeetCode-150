#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void combination(int i, vector<int> &candidates, vector<vector<int>> &ans,
                     vector<int> &list, int target)
    {
        if (target == 0)
        {
            ans.push_back(list);
            return;
        }

        if (i >= candidates.size() || target < 0)
            return;

        list.push_back(candidates[i]);
        combination(i, candidates, ans, list, target - candidates[i]);
        list.pop_back();
        combination(i + 1, candidates, ans, list, target);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> list;
        combination(0, candidates, ans, list, target);
        return ans;
    }
};