/*
재귀적으로....
딱히 설명이 필요할것 같지 않다.
*/

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root) {
			invertTree(root->left);
			invertTree(root->right);

			TreeNode* tmp = root->left;
			root->left = root->right;
			root->right = tmp;
		}
		return root;
	}
};
