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

class Solution
{
    int preInd = 0;
    int inInd = 0;

private:
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int limit)
    {
        if (preInd >= preorder.size())
            return NULL;
        if (inorder[inInd] == limit)
        {
            inInd++;
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preInd++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, limit);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return dfs(preorder, inorder, INT_MAX);
    }
};