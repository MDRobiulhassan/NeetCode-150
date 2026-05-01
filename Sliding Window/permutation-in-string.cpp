// Zoho Accolite Amazon Microsoft OYO Rooms Samsung Snapdeal Citrix Walmart MAQ
// Software Cisco

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < n; i++)
        {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count1[i] == count2[i])
                matches++;
        }

        int l = 0;
        for (int r = n; r < m; r++)
        {
            if (matches == 26)
                return true;

            int index = s2[r] - 'a';
            count2[index]++;

            if (count2[index] == count1[index])
                matches++;
            else if (count2[index] == count1[index] + 1)
                matches--;

            index = s2[l] - 'a';
            count2[index]--;

            if (count2[index] == count1[index])
                matches++;
            else if (count2[index] == count1[index] - 1)
                matches--;

            l++;
        }

        return matches == 26;
    }
};