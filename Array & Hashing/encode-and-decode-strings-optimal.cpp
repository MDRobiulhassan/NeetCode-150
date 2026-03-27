#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &s)
    {
        string res = "";

        for (string &str : s)
            res += (to_string(str.size()) + "#" + str);

        return res;
    }

    vector<string> decode(string &s)
    {

        vector<string> res;

        int i = 0;
        while (i < s.size())
        {
            int j = i;

            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);

            res.push_back(word);

            i = j + 1 + len;
        }

        return res;
    }
};