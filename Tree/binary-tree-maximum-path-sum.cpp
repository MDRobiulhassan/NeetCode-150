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
    int height(TreeNode *node, int &sum)
    {
        if (node == NULL)
            return 0;

        int lh = max(0, height(node->left, sum));
        int rh = max(0, height(node->right, sum));

        sum = max(sum, node->val + lh + rh);
        return node->val + max(lh, rh);
    }

    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        height(root, sum);
        return sum;
    }
};