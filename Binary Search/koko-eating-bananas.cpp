#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int l = 1, r = piles[n - 1];
        int ans = r;

        while (l <= r)
        {
            int k = l + (r - l) / 2;

            long long totalTime = 0;
            for (int p : piles)
                totalTime += ceil(double(p) / k);

            if (totalTime <= h)
            {
                ans = k;
                r = k - 1;
            }
            else
                l = k + 1;
        }

        return ans;
    }
};