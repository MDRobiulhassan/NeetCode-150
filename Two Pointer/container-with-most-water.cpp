#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();

        int l = 0, r = n - 1;
        int ans = 0;
        while (l < r)
        {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(area, ans);

            if (height[l] > height[r])
                r--;
            else
                l++;
        }

        return ans;
    }
};