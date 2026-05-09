#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<long long> stack;
    long long min = 0;
    MinStack() {}

    void push(int val)
    {
        if (stack.empty())
        {
            stack.push(0);
            min = val;
        }
        else
        {
            long long diff = val - min;
            stack.push(diff);
            if (diff < 0)
                min = val;
        }
    }

    void pop()
    {
        long long diff = stack.top();
        stack.pop();

        if (diff < 0)
            min = min - diff;
    }

    int top()
    {
        long long diff = stack.top();
        if (diff > 0)
            return min + diff;
        else
            return min;
    }

    int getMin() { return min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */