/*
Runtime: 36 ms, faster than 97.92% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 32.9 MB, less than 96.78% of C++ online submissions for Merge Two Binary Trees.
*/


class Solution
{
public:
    TreeNode *merge(TreeNode *t1, TreeNode *t2){
        if(!t1 && !t2) return nullptr;

        if(t1 && t2){
            t1->val += t2->val;
            t1->left = merge(t1->left, t2->left);
            t1->right = merge(t1->right, t2->right);
        } else if(!t1 && t2){
            t1 = t2;
        }
        return t1;
    }

    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if(!t1 && !t2) return nullptr;
        if(!t1 && t2) return t2;
        if(t1 && !t2) return t1;

        t1->val += t2->val;
        t1->left = merge(t1->left, t2->left);
        t1->right = merge(t1->right, t2->right);
        return t1;
    }
};
