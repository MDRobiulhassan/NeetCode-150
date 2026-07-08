#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> count(26, 0);

        for (char ch : tasks)
            count[ch - 'A']++;

        priority_queue<int> maxHeap;
        for (int cnt : count)
        {
            if (cnt > 0)
                maxHeap.push(cnt);
        }

        int time = 0;
        queue<pair<int, int>> q;

        while (!maxHeap.empty() || !q.empty())
        {
            time++;

            if (!maxHeap.empty())
            {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();

                if (cnt > 0)
                    q.push({cnt, time + n});
            }

            if (!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};