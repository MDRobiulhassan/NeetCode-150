#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num(nums.begin(), nums.end());

        int longest = 0;
        for (auto it : num)
        {
            if (num.find(it - 1) == num.end())
            {
                int len = 1;
                while (num.find(it + len) != num.end())
                    len++;
                longest = max(len, longest);
            }
        }

        return longest;
    }
};