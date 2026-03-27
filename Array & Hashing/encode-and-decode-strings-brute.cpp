// https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &s)
    {
        string encodedString = "";

        for (string str : s)
            encodedString += (str + "#");

        return encodedString;
    }

    vector<string> decode(string &s)
    {
        vector<string> decodedString;

        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                decodedString.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }

        return decodedString;
    }
};