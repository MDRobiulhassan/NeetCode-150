#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    Trie *links[26] = {};
    bool flag = false;

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    void put(char ch, Trie *node) { links[ch - 'a'] = node; }

    Trie *get(char ch) { return links[ch - 'a']; }

    bool isEnd() { return flag; }

    void setEnd() { flag = true; }
};

class WordDictionary
{
public:
    Trie *root;
    WordDictionary() { root = new Trie(); }

    void addWord(string word)
    {
        Trie *node = root;

        for (char ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new Trie);
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool dfs(string &word, int index, Trie *node)
    {
        if (index == word.size())
            return node->isEnd();

        char ch = word[index];

        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->links[i] != nullptr)
                {
                    if (dfs(word, index + 1, node->links[i]))
                        return true;
                }
            }
            return false;
        }

        if (!node->containsKey(ch))
            return false;

        return dfs(word, index + 1, node->get(ch));
    }

    bool search(string word) { return dfs(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */