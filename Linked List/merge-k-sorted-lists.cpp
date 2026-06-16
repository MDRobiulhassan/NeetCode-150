#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare
{
public:
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;

        for (auto it : lists)
        {
            if (it != NULL)
                pq.push(it);
        }

        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push(node->next);
        }

        return head->next;
    }
};