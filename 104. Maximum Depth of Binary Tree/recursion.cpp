/**
 * Runtime: 4 ms, faster than 98.83% of C++ online submissions for Maximum Depth of Binary Tree.
 * Memory Usage: 18.9 MB, less than 97.29% of C++ online submissions for Maximum Depth of Binary Tree.
 */

class Solution
{
public:
    int max_cnt = 0;
    void goDown(TreeNode *root, int cnt)
    {
        if (!root)
            return;

        max_cnt = max(max_cnt, cnt);
        goDown(root->left, cnt + 1);
        goDown(root->right, cnt + 1);
    }

    int maxDepth(TreeNode *root)
    {
        goDown(root, 1);
        return max_cnt;
    }
};
