#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.size();
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {
                '}',
                '{',
            },
            {']', '['}};

        for (char ch : s)
        {
            if (closeToOpen.count(ch))
            {
                if (!st.empty() && st.top() == closeToOpen[ch])
                    st.pop();
                else
                    return false;
            }
            else
                st.push(ch);
        }

        return st.empty();
    }
};