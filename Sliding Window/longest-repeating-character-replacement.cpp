#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> count;
        int n = s.size();

        int l = 0, maxf = 0, ans = 0;
        for (int r = 0; r < n; r++)
        {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while ((r - l + 1) - maxf > k)
            {
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};