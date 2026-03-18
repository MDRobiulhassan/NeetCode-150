#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (string word : strs)
        {
            vector<int> freq(26, 0);

            for (char ch : word)
                freq[ch - 'a']++;

            string key = "";
            for (int it : freq)
                key += to_string(it) + "#";

            mp[key].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};