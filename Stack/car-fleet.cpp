#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> pair;

        for (int i = 0; i < n; i++)
        {
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());

        double prevTime = (double)(target - pair[0].first) / pair[0].second;
        int fleet = 1;
        for (int i = 1; i < n; i++)
        {
            double curTime = (double)(target - pair[i].first) / pair[i].second;

            if (curTime > prevTime)
            {
                fleet++;
                prevTime = curTime;
            }
        }

        return fleet;
    }
};