#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> freq;

        for (string word : strs)
        {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            freq[sortedWord].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto it : freq)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};