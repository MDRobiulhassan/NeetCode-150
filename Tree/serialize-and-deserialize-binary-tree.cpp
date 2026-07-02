#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";

        string ans = "";
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node)
                {
                    ans += to_string(node->val) + ',';
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                    ans += "null,";
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        vector<string> vals;
        string temp;

        for (char c : data)
        {
            if (c == ',')
            {
                vals.push_back(temp);
                temp.clear();
            }
            else
                temp += c;
        }

        TreeNode *root = new TreeNode(stoi(vals[0]));
        queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < vals.size())
        {
            TreeNode *node = q.front();
            q.pop();

            if (vals[i] != "null")
            {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            if (vals[i] != "null")
            {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};