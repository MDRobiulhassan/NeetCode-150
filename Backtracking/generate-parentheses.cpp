#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int open, int close, vector<string> &ans, string &par,
                  int n)
    {
        if (open == n && close == n)
        {
            ans.push_back(par);
            return;
        }

        if (open < n)
        {
            par += '(';
            generate(open + 1, close, ans, par, n);
            par.pop_back();
        }

        if (close < open)
        {
            par += ')';
            generate(open, close + 1, ans, par, n);
            par.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string par = "";
        generate(0, 0, ans, par, n);
        return ans;
    }
};