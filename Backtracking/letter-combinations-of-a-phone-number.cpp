#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int i, string &digits, vector<string> &ans, string &s,
                  vector<string> &keyMap)
    {

        if (i == digits.size())
        {
            ans.push_back(s);
            return;
        }

        string letters = keyMap[digits[i] - '2'];

        for (char ch : letters)
        {
            s.push_back(ch);
            generate(i + 1, digits, ans, s, keyMap);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {

        if (digits.empty())
            return {};

        vector<string> keyMap = {"abc", "def", "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string s;

        generate(0, digits, ans, s, keyMap);

        return ans;
    }
};