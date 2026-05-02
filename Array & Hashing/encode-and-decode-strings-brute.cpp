// https://www.geeksforgeeks.org/problems/encode-and-decode-strings/1

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
//         string encodedString = "";

//         for (string str : s)
//             encodedString += (str + "#");

//         return encodedString;
//     }

//     vector<string> decode(string &s)
//     {
//         vector<string> decodedString;

//         int start = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '#')
//             {
//                 decodedString.push_back(s.substr(start, i - start));
//                 start = i + 1;
//             }
//         }

//         return decodedString;
//     }
// };