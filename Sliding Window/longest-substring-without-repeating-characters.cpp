#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> charSet;
        int n = s.size();

        int l = 0, ans = 0;
        for (int r = 0; r < n; r++)
        {
            while (charSet.find(s[r]) != charSet.end())
            {
                charSet.erase(s[l]);
                l++;
            }

            charSet.insert(s[r]);
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};