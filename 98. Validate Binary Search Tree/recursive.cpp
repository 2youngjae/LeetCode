/**
 * @file recursive.cpp
 * @author 2YoungJae (dldudwo10@naver.com)
 * @brief
 * @version 0.1
 * @date 2021-05-23
 * @copyright Copyright (c) 2021
 *
 * Runtime: 12 ms, faster than 56.83% of C++ online submissions for Validate
 * Binary Search Tree. Memory Usage: 21.7 MB, less than 42.01% of C++ online
 * submissions for Validate Binary Search Tree.
 *
 * Time complexity : O(n) - n is a number of nodes
 *
 */

#include <climits>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }

  bool isValidBST(TreeNode* root, long min, long max) {
    if (!root) return true;
    if (root->val <= min || root->val >= max) return false;
    return isValidBST(root->left, min, root->val) &&
           isValidBST(root->right, root->val, max);
  }
};

int main() { return 0; }