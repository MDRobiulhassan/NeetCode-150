#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int n = st.top();
                st.pop();
                int m = st.top();
                st.pop();

                if (token == "+")
                    st.push(n + m);
                else if (token == "-")
                    st.push(m - n);
                else if (token == "*")
                    st.push(n * m);
                else
                    st.push(m / n);
            }
            else
                st.push(stoi(token));
        }

        return st.top();
    }
};