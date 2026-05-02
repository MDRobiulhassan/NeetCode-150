#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
            return "";

        int n = s.size();
        int m = t.size();

        map<char, int> t_count, window;
        for (int i = 0; i < t.size(); i++)
            t_count[t[i]]++;

        int have = 0, need = t_count.size();
        int minLen = INT_MAX;
        pair<int, int> ind = {-1, -1};
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            char c = s[r];
            window[c]++;

            if (t_count.count(c) && window[c] == t_count[c])
                have++;

            while (have == need)
            {
                if ((r - l + 1) < minLen)
                {
                    minLen = r - l + 1;
                    ind = {l, r};
                }

                window[s[l]]--;
                if (t_count.count(s[l]) && window[s[l]] < t_count[s[l]])
                    have--;
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(ind.first, minLen);
    }
};