#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    void insertBetween(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }

    void connectRandomPointer(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }
    }

    Node *getCopy(Node *head)
    {
        Node *temp = head;
        Node *dummyNode = new Node(-1), *res = dummyNode;

        while (temp)
        {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

    Node *copyRandomList(Node *head)
    {
        insertBetween(head);
        connectRandomPointer(head);
        return getCopy(head);
    }
};