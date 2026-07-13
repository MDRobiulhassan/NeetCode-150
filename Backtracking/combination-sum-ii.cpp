#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int idx, vector<int> &candidates, vector<vector<int>> &ans,
                  vector<int> &list, int target)
    {
        if (target == 0)
        {
            ans.push_back(list);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;

            list.push_back(candidates[i]);
            generate(i + 1, candidates, ans, list, target - candidates[i]);
            list.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> list;
        generate(0, candidates, ans, list, target);
        return ans;
    }
};