#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &arr)
    {
        int n = arr.size();
        string res = "";
        for (int i = 0; i < n; i++)
        {
            res += to_string(arr[i].size()) + "/;" + arr[i];
        }
        return res;
    }

    vector<string> decode(string &s)
    {
        vector<string> ans;
        int i = 0, n = s.size();
        while (i < n)
        {
            int j = i;
            while (s[j] != '/')
                j++;
            int len = stoi(s.substr(i, j - i));

            i = j + 2;
            ans.push_back(s.substr(i, len));
            i += len;
        }

        return ans;
    }
};

// Old Solution with # as a separator, which is not a good idea as the string can contain # as well
// class Solution
// {
// public:
//     string encode(vector<string> &s)
//     {
//         string res = "";

//         for (string &str : s)
//             res += (to_string(str.size()) + "#" + str);

//         return res;
//     }

//     vector<string> decode(string &s)
//     {

//         vector<string> res;

//         int i = 0;
//         while (i < s.size())
//         {
//             int j = i;

//             while (s[j] != '#')
//                 j++;

//             int len = stoi(s.substr(i, j - i));
//             string word = s.substr(j + 1, len);

//             res.push_back(word);

//             i = j + 1 + len;
//         }

//         return res;
//     }
// };