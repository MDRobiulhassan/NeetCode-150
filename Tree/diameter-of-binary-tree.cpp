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
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    int dfs(TreeNode *root, int &d)
    {
        if (!root)
            return 0;

        int left = dfs(root->left, d);
        int right = dfs(root->right, d);
        d = max(left + right, d);
        return 1 + max(left, right);
    }
};