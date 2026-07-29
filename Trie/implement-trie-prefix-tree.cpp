#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    Node *get(char ch) { return links[ch - 'a']; }

    void put(char ch, Node *node) { links[ch - 'a'] = node; }

    bool isEnd() { return flag; }

    void setEnd() { flag = true; }
};

class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }

    void insert(string word)
    {
        Node *node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new Node);
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */