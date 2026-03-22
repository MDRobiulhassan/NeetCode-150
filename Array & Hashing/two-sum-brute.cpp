#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;

        vector<int> numsCopy = nums;
        unordered_map<int, vector<int>> ind;
        sort(numsCopy.begin(), numsCopy.end());

        for (int i = 0; i < nums.size(); i++)
            ind[nums[i]].push_back(i);

        while (l < r)
        {
            int sum = numsCopy[l] + numsCopy[r];
            if (sum == target)
            {
                if (numsCopy[l] == numsCopy[r])
                    return {ind[numsCopy[l]][0], ind[numsCopy[l]][1]};
                return {ind[numsCopy[l]][0], ind[numsCopy[r]][0]};
            }
            if (sum > target)
                r--;
            else
                l++;
        }

        return {};
    }
};