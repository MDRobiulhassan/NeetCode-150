#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> keyStore;
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        auto &values = keyStore[key];
        int l = 0, r = values.size() - 1;
        string ans = "";

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (values[mid].first <= timestamp)
            {
                l = mid + 1;
                ans = values[mid].second;
            }
            else
                r = mid - 1;
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */