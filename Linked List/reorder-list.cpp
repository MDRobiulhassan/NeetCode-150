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

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *curr = slow->next;
        slow->next = NULL;
        ListNode *prev = NULL;

        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode *l1 = head, *l2 = prev;

        while (l2)
        {
            ListNode *temp1 = l1->next;
            ListNode *temp2 = l2->next;

            l1->next = l2;
            l2->next = temp1;

            l1 = temp1;
            l2 = temp2;
        }
    }
};